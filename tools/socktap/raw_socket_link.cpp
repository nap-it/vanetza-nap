#include "raw_socket_link.hpp"
#include "rssi_reader.hpp"
#include <vanetza/access/data_request.hpp>
#include <array>
#include <vanetza/access/ethertype.hpp>
#include <vanetza/net/ethernet_header.hpp>
#include <iostream>
#include <sstream>
#include <chrono>
#include <sys/socket.h>
#include <linux/filter.h>

using namespace vanetza;
using namespace std::chrono;

namespace {
    constexpr std::size_t layers_ = num_osi_layers(OsiLayer::Physical, OsiLayer::Application);
}

RawSocketLink::RawSocketLink(boost::asio::generic::raw_protocol::socket&& socket, const std::string& device_name, bool rssi_enabled) :
    socket_(std::move(socket)), receive_buffer_(2048, 0x00),
    receive_endpoint_(socket_.local_endpoint()),
    rssi_enabled_(rssi_enabled)
{
    // BPF filter to only accept GeoNetworking packets (ethertype 0x8947)
    struct sock_filter bpf_code[] = {
        { 0x28, 0, 0, 0x0000000c },  // ldh [12] - load ethertype
        { 0x15, 0, 1, 0x00008947 },  // jeq #0x8947, jt 2, jf 3
        { 0x06, 0, 0, 0x0000ffff },  // ret #65535 - accept
        { 0x06, 0, 0, 0x00000000 },  // ret #0 - reject
    };

    struct sock_fprog bpf_filter = {
        .len = sizeof(bpf_code) / sizeof(struct sock_filter),
        .filter = bpf_code,
    };

    // Apply the BPF filter
    if (setsockopt(socket_.native_handle(), SOL_SOCKET, SO_ATTACH_FILTER,
        &bpf_filter, sizeof(bpf_filter)) < 0) {
        std::cout << "Could not apply BPF filter to raw socket link. Proceeding with unfiltered socket." << std::endl;
    }

    // Start RSSI reader if enabled
    if (rssi_enabled_) {
        start_rssi_reader(device_name);
    }
}

void RawSocketLink::request(const access::DataRequest& request, std::unique_ptr<ChunkPacket> packet)
{
    packet->layer(OsiLayer::Link) = create_ethernet_header(request.destination_addr, request.source_addr, request.ether_type);
    transmit(std::move(packet));
}

std::size_t RawSocketLink::transmit(std::unique_ptr<ChunkPacket> packet)
{
    std::array<vanetza::ByteBuffer, layers_> local_buffers;
    std::array<boost::asio::const_buffer, layers_> const_buffers;
    for (auto& layer : osi_layer_range<OsiLayer::Physical, OsiLayer::Application>()) {
        const auto index = distance(OsiLayer::Physical, layer);
        packet->layer(layer).convert(local_buffers[index]);
        const_buffers[index] = boost::asio::buffer(local_buffers[index]);
    }

    std::lock_guard<std::mutex> lock(xmit_mtx_);
    return socket_.send(const_buffers);
}

void RawSocketLink::indicate(IndicationCallback callback)
{
    callback_ = callback;
}

void RawSocketLink::do_receive()
{
    // Blocking receive loop (runs in dedicated thread)
    while (true) {
        boost::system::error_code ec;
        std::size_t bytes_received = socket_.receive_from(
            boost::asio::buffer(receive_buffer_), receive_endpoint_, 0, ec);
        on_read(ec, bytes_received);
    }
}

void RawSocketLink::on_read(const boost::system::error_code& ec, std::size_t read_bytes)
{
    if (!ec) {
        ByteBuffer buffer(receive_buffer_.begin(), receive_buffer_.begin() + read_bytes);
        CohesivePacket packet(std::move(buffer), OsiLayer::Physical);
        boost::optional<EthernetHeader> eth = parse_ethernet_header(packet);

        if (eth && eth->type == access::ethertype::GeoNetworking) {
            // Record reception timestamp
            double time_reception = (double) duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000000.0;

            // Extract source MAC address from Ethernet header
            std::stringstream stream;
            stream << eth->source;
            std::string source_mac = stream.str();

            // Always set source MAC and timestamp
            packet.source = source_mac;
            packet.time_received = time_reception;
            packet.rssi = -255;  // Default "unavailable" value

            // Populate RSSI and channel data if enabled
            if (rssi_enabled_) {
                int nrssi = get_rssi(source_mac);
                if (nrssi != 1) {  // 1 means not found
                    packet.rssi = nrssi;
                }
                packet.mcs = get_mcs();

                Survey s = get_survey();
                packet.frequency = s.frequency;
                packet.noise = s.noise;
                packet.chan_busy_time = s.chan_busy_time;
                packet.chan_rx_time = s.chan_rx_time;
                packet.chan_tx_time = s.chan_tx_time;
            }

            if (callback_) {
                callback_(std::move(packet), *eth);
            }
        }
    }
}

boost::optional<EthernetHeader> RawSocketLink::parse_ethernet_header(vanetza::CohesivePacket& packet) const
{
    packet.set_boundary(OsiLayer::Physical, 0);
    if (packet.size(OsiLayer::Link) < EthernetHeader::length_bytes) {
        std::cerr << "Router dropped invalid packet (too short for Ethernet header)\n";
    } else {
        packet.set_boundary(OsiLayer::Link, EthernetHeader::length_bytes);
        auto link_range = packet[OsiLayer::Link];
        return decode_ethernet_header(link_range.begin(), link_range.end());
    }

    return boost::none;
}
