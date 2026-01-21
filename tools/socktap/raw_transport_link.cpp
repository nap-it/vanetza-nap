#include "raw_transport_link.hpp"
#include "vanetza/access/ethertype.hpp"
#include <cerrno>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <mutex>
#include <thread>
#include <vanetza/access/data_request.hpp>
#include <vanetza/net/ethernet_header.hpp>

#include "vanetza/net/osi_layer.hpp"
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <boost/asio.hpp>

#define MAXLINE 1024

using namespace vanetza;
using namespace std::chrono;

std::mutex xtmi_mtx_transport;

RawTransportLink::RawTransportLink(boost::asio::ip::udp::socket&& socket, const std::string& device_name, uint16_t udp_port)
    : socket_(std::move(socket)), receive_buffer_(2048, 0x00), receive_endpoint_() {
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, device_name.c_str(), IFNAMSIZ - 1);

    if (setsockopt(socket_.native_handle(), SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr)) < 0) {
        std::cerr << "WARNING: Could not bind to " << device_name << ": " << strerror(errno) << " (errno=" << errno << ")" << std::endl;
        std::cerr << "Will receive UDP on all interfaces instead" << std::endl;
    }
}

void RawTransportLink::request(const access::DataRequest& request, std::unique_ptr<ChunkPacket> packet) {
    packet->layer(OsiLayer::Link) = create_ethernet_header(request.destination_addr, request.source_addr, request.ether_type);
    transmit(std::move(packet));
}

std::size_t RawTransportLink::transmit(std::unique_ptr<ChunkPacket> packet) {
    std::array<vanetza::ByteBuffer, layers_> buffers_;
    std::array<boost::asio::const_buffer, layers_> const_buffers;
    for (auto& layer : osi_layer_range<OsiLayer::Physical, OsiLayer::Application>()) {
        const auto index = distance(OsiLayer::Physical, layer);
        packet->layer(layer).convert(buffers_[index]);
        const_buffers[index] = boost::asio::buffer(buffers_[index]);
    }

    xtmi_mtx_transport.lock();
    std::size_t res = socket_.send(const_buffers);
    xtmi_mtx_transport.unlock();
    return res;
}

void RawTransportLink::indicate(IndicationCallback callback) {
    callback_ = callback;
}

void RawTransportLink::do_receive() {
    while (true) {
        boost::system::error_code ec;
        std::size_t bytesReceived = socket_.receive_from(boost::asio::buffer(receive_buffer_), receive_endpoint_, 0, ec);

        if (ec) {
            std::cerr << "Socket receive error: " << ec.message() << std::endl;
        }

        on_read(ec, bytesReceived);
    }
}

void RawTransportLink::on_read(const boost::system::error_code& ec, std::size_t read_bytes) {
    if (!ec && read_bytes > 0) {
        std::cout << "Received " << read_bytes << " bytes from " << receive_endpoint_.address().to_string() << ":" << receive_endpoint_.port() << std::endl;

        // TODO: Process UDP payload and pass to callback when needed
        // For now, just log that we received the packet
    } else if (ec) {
        std::cerr << "Receive error: " << ec.message() << std::endl;
    }
}
