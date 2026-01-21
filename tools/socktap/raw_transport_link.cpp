#include "raw_transport_link.hpp"
#include <boost/optional/optional.hpp>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <mutex>
#include <string>
#include <vanetza/access/data_request.hpp>
#include <vanetza/net/ethernet_header.hpp>

#include "vanetza/net/osi_layer.hpp"
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <boost/asio.hpp>

#define MAXLINE 1024

using namespace vanetza;

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
		// Log the hex representation of the payload
        std::string payload(receive_buffer_.begin(), receive_buffer_.begin() + read_bytes);
		std::cout << "Payload (hex): ";
		for (unsigned char c : payload) {
			std::cout << std::hex << static_cast<int>(c) << " ";
		}

        // Validate minimum size
        if (read_bytes < 4) {
            std::cerr << "[ON_READ] Packet too small for BTP header" << std::endl;
            return;
        }

        // Parse BTP header from payload
        // BTP-B header format:
        //   Bytes 0-1: Destination port (big-endian)
        //   Bytes 2-3: INFO
        uint16_t dst_port = ntohs(*reinterpret_cast<const uint16_t*>(&receive_buffer_[0]));
        uint16_t info = ntohs(*reinterpret_cast<const uint16_t*>(&receive_buffer_[2]));
        std::cout << "[UDP] BTP parsed: dst=" << dst_port 
                  << " (0x" << std::hex << dst_port << std::dec << ")"
                  << " info=" << info << std::endl;
		
        // Extract CAM payload (everything AFTER BTP header)
        vanetza::ByteBuffer cam_payload(
            receive_buffer_.begin() + 4,  // Skip 4-byte BTP header
            receive_buffer_.begin() + read_bytes
        );
        
        std::cout << "[UDP] CAM payload: " << cam_payload.size() << " bytes" << std::endl;
		if (udp_btp_callback_) {
			udp_btp_callback_(dst_port, info, std::move(cam_payload));
		} else {
			std::cerr << "[UDP] WARNING: No UDP callback set!" << std::endl;
		}
    }
}
