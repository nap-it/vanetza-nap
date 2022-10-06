#include "ethernet_device.hpp"
#include "cam_application.hpp"
#include "denm_application.hpp"
#include "cpm_application.hpp"
#include "vam_application.hpp"
#include "spatem_application.hpp"
#include "mapem_application.hpp"
#include "link_layer.hpp"
#include "positioning.hpp"
#include "router_context.hpp"
#include "security.hpp"
#include "time_trigger.hpp"
#include "config.hpp"
#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/program_options.hpp>
#include <boost/asio/ip/host_name.hpp>
#include <iostream>
#include <prometheus/exposer.h>
#include <random>

namespace asio = boost::asio;
namespace gn = vanetza::geonet;
namespace po = boost::program_options;
using namespace vanetza;
using namespace prometheus;

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(0,1000); // guaranteed unbiased

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

        const char* device_name = config_s.interface.c_str();
        EthernetDevice device(device_name);
        vanetza::MacAddress mac_address = device.address();

        std::cout << config_s.mac_address << std::endl;
        if (config_s.mac_address != "") {
            std::cout << "Using MAC address: " << config_s.mac_address << "." << std::endl;

            if (!parse_mac_address(config_s.mac_address, mac_address)) {
                std::cerr << "The specified MAC address is invalid." << std::endl;
                return 1;
            }
        }

        const std::string link_layer_name = "ethernet";
        auto link_layer =  create_link_layer(io_service, device, link_layer_name, config_s.rssi_enabled);
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

        const auto host_name = boost::asio::ip::host_name();
        Mqtt *local_mqtt = new Mqtt(host_name + "_" + to_string(uni(rng)), config_s.local_mqtt_broker, config_s.local_mqtt_port);
        Mqtt *remote_mqtt = NULL;
        if (config_s.remote_mqtt_port != 0) {
            if (config_s.remote_mqtt_username != "") {
                remote_mqtt = new Mqtt(host_name + "_" + to_string(uni(rng)), config_s.remote_mqtt_broker, config_s.remote_mqtt_port, config_s.remote_mqtt_username, config_s.remote_mqtt_password);
            } else {
                remote_mqtt = new Mqtt(host_name + "_" + to_string(uni(rng)), config_s.remote_mqtt_broker, config_s.remote_mqtt_port);
            }
        }
        Dds *dds = new Dds(config_s.to_dds_key, config_s.from_dds_key);

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

        RouterContext context(mib, trigger, *positioning, security.get(), config_s.ignore_own_messages, config_s.ignore_rsu_messages, io_service);
        context.require_position_fix(vm.count("require-gnss-fix") > 0);
        context.set_link_layer(link_layer.get());

        std::map<std::string, std::unique_ptr<Application>> apps;

        start_application_thread();

        if (config_s.cam.enabled) {
            std::unique_ptr<CamApplication> cam_app {
                new CamApplication(*positioning, context.get_dccp().get_trigger().runtime(), local_mqtt, remote_mqtt, dds, config_s, metrics_s)
            };
            cam_app->set_interval(std::chrono::milliseconds(config_s.cam.periodicity));
            apps.emplace("cam", std::move(cam_app));
        }

        if (config_s.denm.enabled) {
            std::unique_ptr<DenmApplication> denm_app {
                new DenmApplication(*positioning, context.get_dccp().get_trigger().runtime(), local_mqtt, remote_mqtt, dds, config_s, metrics_s)
            };
            denm_app->set_interval(std::chrono::milliseconds(config_s.denm.periodicity));
            apps.emplace("denm", std::move(denm_app));
        }

        if (config_s.cpm.enabled) {
            std::unique_ptr<CpmApplication> cpm_app {
                    new CpmApplication(*positioning, context.get_dccp().get_trigger().runtime(), local_mqtt, remote_mqtt, dds, config_s, metrics_s)
            };
            cpm_app->set_interval(std::chrono::milliseconds(config_s.cpm.periodicity));
            apps.emplace("cpm", std::move(cpm_app));
        }

        if (config_s.vam.enabled) {
            std::unique_ptr<VamApplication> vam_app {
                    new VamApplication(*positioning, context.get_dccp().get_trigger().runtime(), local_mqtt, remote_mqtt, dds, config_s, metrics_s)
            };
            vam_app->set_interval(std::chrono::milliseconds(config_s.vam.periodicity));
            apps.emplace("vam", std::move(vam_app));
        }

        if (config_s.spatem.enabled) {
            std::unique_ptr<SpatemApplication> spatem_app {
                    new SpatemApplication(*positioning, context.get_dccp().get_trigger().runtime(), local_mqtt, remote_mqtt, dds, config_s, metrics_s)
            };
            spatem_app->set_interval(std::chrono::milliseconds(config_s.spatem.periodicity));
            apps.emplace("spatem", std::move(spatem_app));
        }

        if (config_s.mapem.enabled) {
            std::unique_ptr<MapemApplication> mapem_app {
                    new MapemApplication(*positioning, context.get_dccp().get_trigger().runtime(), local_mqtt, remote_mqtt, dds, config_s, metrics_s)
            };
            mapem_app->set_interval(std::chrono::milliseconds(config_s.mapem.periodicity));
            apps.emplace("mapem", std::move(mapem_app));
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
