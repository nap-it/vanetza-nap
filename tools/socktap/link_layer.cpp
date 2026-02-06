#include "link_layer.hpp"
#include "raw_socket_link.hpp"
#include "tcp_link.hpp"
#include "udp_link.hpp"
#include <vanetza/access/ethertype.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/generic/raw_protocol.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/udp.hpp>
#include <iostream>
#include <thread>

#ifdef SOCKTAP_WITH_CUBE_EVK
#   include "nfiniity_cube_evk_link.hpp"
#endif

#ifdef SOCKTAP_WITH_COHDA_LLC
#   include "cohda_link.hpp"
#endif

#ifdef SOCKTAP_WITH_AUTOTALKS
#   include "autotalks_link.hpp"
#   include "autotalks.hpp"
#endif

#ifdef SOCKTAP_WITH_RPC
#   include "rpc_link.hpp"
#endif

boost::optional<std::pair<boost::asio::ip::address, unsigned short>> parse_ip_port(const std::string& ip_port)
{
    using opt_ip_port = boost::optional<std::pair<boost::asio::ip::address, unsigned short>>;

    std::size_t ip_len = ip_port.find_last_of(":");
    if (ip_len == std::string::npos) {
        // error: port not found
        std::cerr << "[" << ip_port << "] Missing port." << std::endl;
        return opt_ip_port();
    }

    std::size_t port = std::strtoul(ip_port.substr(ip_len + 1).c_str(), NULL, 10);
    if (port < 1 || port > 65535) {
        // error: port out of range
        std::cerr << "[" << ip_port << "] Port " << port << " out of range (1-65535)." << std::endl;
        return opt_ip_port();
    }

    boost::system::error_code ec;
    boost::asio::ip::address ip = boost::asio::ip::make_address(ip_port.substr(0, ip_len), ec);
    if (ec) {
        // error: IP-address invalid
        std::cerr << "[" << ip_port << "] Invalid IP-address: " << ec.message() << std::endl;
        return opt_ip_port();
    }

    return opt_ip_port({ip, port});
}

std::unique_ptr<LinkLayer>
create_link_layer(boost::asio::io_context& io_context, const EthernetDevice& device, const std::string& name, const std::string& device_name, bool rssi_enabled, std::string ipv4_address, int ipv4_port)
{
    std::unique_ptr<LinkLayer> link_layer;

    if (name == "ethernet" || name == "cohda") {
        boost::asio::generic::raw_protocol raw_protocol(AF_PACKET, vanetza::access::ethertype::GeoNetworking.net());
        boost::asio::generic::raw_protocol::socket raw_socket(io_context, raw_protocol);
        raw_socket.bind(device.endpoint(AF_PACKET));

        if (name == "ethernet") {
            RawSocketLink* rawSocketLink = new RawSocketLink { std::move(raw_socket), device_name, rssi_enabled };
            link_layer.reset(rawSocketLink);
            std::thread receive_thread = std::thread([rawSocketLink]() {
                rawSocketLink->do_receive();
            });
            receive_thread.detach();
        } else if (name == "cohda") {
#ifdef SOCKTAP_WITH_COHDA_LLC
            link_layer.reset(new CohdaLink { std::move(raw_socket) });
#endif
        }
    } else if (name == "udp") {
        namespace ip = boost::asio::ip;
        if (ipv4_address != "" && ipv4_port != 0) {
            boost::asio::ip::udp::endpoint multicast(ip::make_address(ipv4_address), ipv4_port);
            link_layer.reset(new UdpLink { io_context, multicast, device });
        } else {
            ip::udp::endpoint multicast(ip::make_address("239.118.122.97"), 8947);
            link_layer.reset(new UdpLink { io_context, multicast, device });
        }

    } else if (name == "autotalks") {
#ifdef SOCKTAP_WITH_AUTOTALKS
        link_layer.reset(new AutotalksLink { io_context });
#endif
    } else if (name == "cube-evk") {
#ifdef SOCKTAP_WITH_CUBE_EVK
        link_layer.reset(new CubeEvkLink { io_context, boost::asio::ip::make_address(vm["cube-ip"].as<std::string>()) });
#endif
    } else if (name == "rpc") {
#ifdef SOCKTAP_WITH_RPC
        boost::asio::ip::tcp::socket socket(io_context);
        boost::asio::ip::tcp::resolver resolver(io_context);
        auto rpc_host = vm["rpc-host"].as<std::string>();
        auto rpc_port = vm["rpc-port"].as<unsigned>();
        auto endpoints = resolver.resolve(rpc_host, std::to_string(rpc_port));
        boost::asio::connect(socket, endpoints);
        link_layer.reset(new RpcLinkLayer {io_context, std::move(socket)});
        if (auto rpc_link_layer = static_cast<RpcLinkLayer*>(link_layer.get())) {
            rpc_link_layer->radio_technology(vm["rpc-radio-technology"].as<std::string>());
            rpc_link_layer->enable_debug(vm["rpc-debug"].as<bool>());
        }
#endif
    }

    return link_layer;
}

void add_link_layer_options(boost::program_options::options_description& options)
{
    options.add_options()
        ("tcp-connect", boost::program_options::value<std::vector<std::string>>()->multitoken(), "Connect to TCP-Host(s). Comma separated list of [ip]:[port].")
        ("tcp-accept", boost::program_options::value<std::vector<std::string>>()->multitoken(), "Accept TCP-Connections. Comma separated list of [ip]:[port].")
    ;
}
