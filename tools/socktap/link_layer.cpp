#include "link_layer.hpp"
#include "raw_socket_link.hpp"
#include "raw_transport_link.hpp"
#include <boost/asio/generic/raw_protocol.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/udp.hpp>
#include <cstdint>
#include <iostream>
#include <linux/if_ether.h>
#include <thread>
#include <vanetza/access/ethertype.hpp>

#ifdef SOCKTAP_WITH_COHDA_LLC
#include "cohda_link.hpp"
#endif

std::unique_ptr<LinkLayer> create_link_layer(boost::asio::io_service& io_service, const EthernetDevice& device, const std::string& name, const std::string& device_name, const bool rssi_enabled) {
    std::unique_ptr<LinkLayer> link_layer;

    if (name == "ethernet" || name == "cohda") {
        boost::asio::generic::raw_protocol raw_protocol(AF_PACKET, vanetza::access::ethertype::GeoNetworking.net());
        boost::asio::generic::raw_protocol::socket raw_socket(io_service, raw_protocol);
        raw_socket.bind(device.endpoint(AF_PACKET));

        if (name == "ethernet") {
            RawSocketLink* rawSocketLink = new RawSocketLink{std::move(raw_socket), device_name, rssi_enabled};
            link_layer.reset(rawSocketLink);
            std::thread receive_thread = std::thread([rawSocketLink]() { rawSocketLink->do_receive(); });
            receive_thread.detach();
        } else if (name == "cohda") {
#ifdef SOCKTAP_WITH_COHDA_LLC
            link_layer.reset(new CohdaLink{std::move(raw_socket)});
#endif
        }
    }

    return link_layer;
}

std::unique_ptr<LinkLayer> create_link_layer_transport(boost::asio::io_service& io_service, const EthernetDevice& device, const std::string& device_name, uint16_t port) {
    std::unique_ptr<LinkLayer> link_layer;

    try {
        boost::asio::ip::udp::socket transport_socket(io_service);
        transport_socket.open(boost::asio::ip::udp::v4());
        transport_socket.set_option(boost::asio::socket_base::reuse_address(true));
        boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address_v4::any(), port);
        transport_socket.bind(endpoint);

        RawTransportLink* transportLink = new RawTransportLink{std::move(transport_socket), device_name, port};
        link_layer.reset(transportLink);

        std::thread receive_thread([transportLink]() { transportLink->do_receive(); });
        receive_thread.detach();

    } catch (std::exception& e) {
        std::cerr << "ERROR: Failed to create UDP socket: " << e.what() << std::endl;
    }

    return link_layer;
}
