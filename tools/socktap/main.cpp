#include "ethernet_device.hpp"
#include "applications/cam_application.hpp"
#include "applications/denm_application.hpp"
#include "applications/cpm_application.hpp"
#include "applications/vam_application.hpp"
#include "applications/spatem_application.hpp"
#include "applications/mapem_application.hpp"
#include "applications/ssem_application.hpp"
#include "applications/srem_application.hpp"
#include "applications/rtcmem_application.hpp"
#include "applications/ivim_application.hpp"
#include "applications/evcsnm_application.hpp"
#include "applications/evrsrm_application.hpp"
#include "applications/imzm_application.hpp"
#include "applications/tistpgm_application.hpp"
#include "applications/mcm_application.hpp"
#include "link_layer.hpp"
#include "positioning.hpp"
#include "router_context.hpp"
#include "security.hpp"
#include "time_trigger.hpp"
#include "config.hpp"
#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <prometheus/exposer.h>
#include <unistd.h>

// DEBUG PURPOSES:
#include <thread>

namespace asio = boost::asio;
namespace gn = vanetza::geonet;
namespace po = boost::program_options;
using namespace vanetza;
using namespace prometheus;

int main(int argc, const char** argv)
{
    po::options_description options("Allowed options");
    options.add_options()
        ("help", "Print out available options.")
        ("config,c", po::value<std::string>()->default_value("config.ini"), "Config file path")
    ;
    add_security_options(options);

    po::variables_map vm;

    try {
        po::store(
            po::command_line_parser(argc, argv)
                .options(options)
                .run(),
            vm
        );
        po::notify(vm);
    } catch (po::error& e) {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << options << std::endl;
        return 1;
    }

    if (vm.count("help")) {
        std::cout << options << std::endl;
        return 1;
    }

    config_t config_s = {};
    read_config(&config_s, vm["config"].as<std::string>());

    try {
        asio::io_service io_service;
        TimeTrigger trigger(io_service);

        // DEBUG PURPOSES
        //std::this_thread::sleep_for(std::chrono::milliseconds(20000));

        const char* device_name = config_s.interface.c_str();
        EthernetDevice device(device_name);
        vanetza::MacAddress mac_address = device.address();

        if (config_s.mac_address != "") {
            std::cout << "Using MAC address: " << config_s.mac_address << "." << std::endl;

            if (!parse_mac_address(config_s.mac_address, mac_address)) {
                std::cerr << "The specified MAC address is invalid." << std::endl;
                return 1;
            }
        }

        const std::string link_layer_name = "ethernet";
        auto link_layer =  create_link_layer(io_service, device, link_layer_name, device_name, config_s.rssi_enabled);
        if (!link_layer) {
            std::cerr << "No link layer '" << link_layer_name << "' found." << std::endl;
            return 1;
        }

        auto signal_handler = [&io_service](const boost::system::error_code& ec, int signal_number) {
            if (!ec) {
                std::cout << "Termination requested." << std::endl;
                io_service.stop();
            }
        };
        asio::signal_set signals(io_service, SIGINT, SIGTERM);
        signals.async_wait(signal_handler);

        // configure management information base
        // TODO: make more MIB options configurable by command line flags
        gn::MIB mib;
        mib.itsGnLocalGnAddr.mid(mac_address);
        mib.itsGnLocalGnAddr.is_manually_configured(true);
        mib.itsGnLocalAddrConfMethod = geonet::AddrConfMethod::Managed;
        mib.itsGnSecurity = false;
        mib.vanetzaDisableBeaconing = !config_s.beacons_enabled;

        // NON_STRICT
        mib.itsGnSnDecapResultHandling = vanetza::geonet::SecurityDecapHandling::Non_Strict;
        mib.itsGnProtocolVersion = 1;
        if (mib.itsGnProtocolVersion != 0 && mib.itsGnProtocolVersion != 1) {
            throw std::runtime_error("Unsupported GeoNetworking version, only version 0 and 1 are supported.");
        }

        auto positioning = create_position_provider(io_service, vm, config_s, trigger.runtime());
        if (!positioning) {
            std::cerr << "Requested positioning method is not available\n";
            return 1;
        }

        auto security = create_security_entity(vm, trigger.runtime(), *positioning);
        if (security) {
            mib.itsGnSecurity = true;
        }

        metrics_t metrics_s = {};

        metrics_s.registry = std::make_shared<Registry>();

        metrics_s.packet_counter = &(BuildCounter()
                             .Name("observed_packets_count_total")
                             .Help("Number of observed packets")
                             .Register(*(metrics_s.registry)));

        metrics_s.latency_counter = &(BuildCounter()
                             .Name("observed_packets_latency_total")
                             .Help("Processing latency of observed packets")
                             .Register(*(metrics_s.registry)));

        Exposer* exposer;
        if (config_s.prometheus_port != 0) {
            exposer = new Exposer("0.0.0.0:" + to_string(config_s.prometheus_port),2,nullptr);
            exposer->RegisterCollectable(metrics_s.registry);
        }

        unsigned int num_threads = std::thread::hardware_concurrency();
        if (num_threads == 0) {
            num_threads = 1;
        }
        if (config_s.num_threads > 0) {
            num_threads = config_s.num_threads;
        }

        RouterContext context(mib, trigger, *positioning, security.get(), config_s.ignore_own_messages, config_s.ignore_rsu_messages, num_threads, io_service);
        context.set_link_layer(link_layer.get());
        context.require_position_fix(vm.count("require-gnss-fix") > 0);

        std::mutex prom_mtx; 

        PubSub* pubsub = new PubSub(config_s, num_threads, prom_mtx);

        std::map<std::string, std::unique_ptr<Application>> apps;

        if (config_s.cam.enabled) {
            std::unique_ptr<CamApplication> cam_app {
                new CamApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, get_router(num_threads), 1, prom_mtx)
            };
            cam_app->set_interval(std::chrono::milliseconds(config_s.cam.periodicity));
            apps.emplace("cam", std::move(cam_app));
        }

        if (config_s.denm.enabled) {
            std::unique_ptr<DenmApplication> denm_app {
                new DenmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 0, prom_mtx)
            };
            denm_app->set_interval(std::chrono::milliseconds(config_s.denm.periodicity));
            apps.emplace("denm", std::move(denm_app));
        }

        if (config_s.cpm.enabled) {
            std::unique_ptr<CpmApplication> cpm_app {
                    new CpmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 0, prom_mtx)
            };
            cpm_app->set_interval(std::chrono::milliseconds(config_s.cpm.periodicity));
            apps.emplace("cpm", std::move(cpm_app));
        }

        if (config_s.vam.enabled) {
            std::unique_ptr<VamApplication> vam_app {
                    new VamApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 1, prom_mtx)
            };
            vam_app->set_interval(std::chrono::milliseconds(config_s.vam.periodicity));
            apps.emplace("vam", std::move(vam_app));
        }

        if (config_s.spatem.enabled) {
            std::unique_ptr<SpatemApplication> spatem_app {
                    new SpatemApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 1, prom_mtx)
            };
            spatem_app->set_interval(std::chrono::milliseconds(config_s.spatem.periodicity));
            apps.emplace("spatem", std::move(spatem_app));
        }

        if (config_s.mapem.enabled) {
            std::unique_ptr<MapemApplication> mapem_app {
                    new MapemApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 1, prom_mtx)
            };
            mapem_app->set_interval(std::chrono::milliseconds(config_s.mapem.periodicity));
            apps.emplace("mapem", std::move(mapem_app));
        }

        if (config_s.ssem.enabled) {
            std::unique_ptr<SsemApplication> ssem_app {
                    new SsemApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            ssem_app->set_interval(std::chrono::milliseconds(config_s.ssem.periodicity));
            apps.emplace("ssem", std::move(ssem_app));
        }

        if (config_s.srem.enabled) {
            std::unique_ptr<SremApplication> srem_app {
                    new SremApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            srem_app->set_interval(std::chrono::milliseconds(config_s.srem.periodicity));
            apps.emplace("srem", std::move(srem_app));
        }

        if (config_s.rtcmem.enabled) {
            std::unique_ptr<RtcmemApplication> rtcmem_app {
                    new RtcmemApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            rtcmem_app->set_interval(std::chrono::milliseconds(config_s.rtcmem.periodicity));
            apps.emplace("rtcmem", std::move(rtcmem_app));
        }

        if (config_s.ivim.enabled) {
            std::unique_ptr<IvimApplication> ivim_app {
                    new IvimApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            ivim_app->set_interval(std::chrono::milliseconds(config_s.ivim.periodicity));
            apps.emplace("ivim", std::move(ivim_app));
        }

        if (config_s.evcsnm.enabled) {
            std::unique_ptr<EvcsnmApplication> evcsnm_app {
                    new EvcsnmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            evcsnm_app->set_interval(std::chrono::milliseconds(config_s.evcsnm.periodicity));
            apps.emplace("evcsnm", std::move(evcsnm_app));
        }

        if (config_s.evrsrm.enabled) {
            std::unique_ptr<EvrsrmApplication> evrsrm_app {
                    new EvrsrmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            evrsrm_app->set_interval(std::chrono::milliseconds(config_s.evrsrm.periodicity));
            apps.emplace("evrsrm", std::move(evrsrm_app));
        }

        if (config_s.imzm.enabled) {
            std::unique_ptr<ImzmApplication> imzm_app {
                    new ImzmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            imzm_app->set_interval(std::chrono::milliseconds(config_s.imzm.periodicity));
            apps.emplace("imzm", std::move(imzm_app));
        }

        if (config_s.tistpgm.enabled) {
            std::unique_ptr<TistpgmApplication> tistpgm_app {
                    new TistpgmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 2, prom_mtx)
            };
            tistpgm_app->set_interval(std::chrono::milliseconds(config_s.tistpgm.periodicity));
            apps.emplace("tistpgm", std::move(tistpgm_app));
        }

        if (config_s.mcm.enabled) {
            std::unique_ptr<McmApplication> mcm_app {
                    new McmApplication(*positioning, context.get_dccp().get_trigger().runtime(), pubsub, config_s, metrics_s, 1, prom_mtx)
            };
            mcm_app->set_interval(std::chrono::milliseconds(config_s.mcm.periodicity));
            apps.emplace("mcm", std::move(mcm_app));
        }

        if (apps.empty()) {
            std::cerr << "Warning: No applications are configured, only GN beacons will be exchanged\n";
        }

        for (const auto& app : apps) {
            std::cout << "Enable application '" << app.first << "'...\n";
            context.enable(app.second.get());
        }

        io_service.run();
    } catch (PositioningException& e) {
        std::cerr << "Exit because of positioning error: " << e.what() << std::endl;
        return 1;
    } catch (std::exception& e) {
        std::cerr << "Exit: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
