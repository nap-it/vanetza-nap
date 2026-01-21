#ifndef RAW_TRANSPORT_LINK_HPP_UNIQUE_ID
#define RAW_TRANSPORT_LINK_HPP_UNIQUE_ID

#include "link_layer.hpp"
#include <array>
#include <boost/asio/ip/udp.hpp>
#include <boost/optional/optional.hpp>
#include <cstdint>
#include <functional>
#include <vanetza/access/interface.hpp>
#include <vanetza/net/ethernet_header.hpp>

class RawTransportLink : public LinkLayer {
public:
    RawTransportLink(boost::asio::ip::udp::socket&&, const std::string& device_name, uint16_t udp_port);
    void request(const vanetza::access::DataRequest&, std::unique_ptr<vanetza::ChunkPacket>) override;
    void indicate(IndicationCallback) override;
    void do_receive();
    // Simplified callback: Just BTP info + CAM payload
    using UdpBtpCallback = std::function<void(
        uint16_t btp_dst_port,
        uint16_t btp_dst_port_info,
        vanetza::ByteBuffer&& cam_payload
    )>;
    void indicate_udp_btp(UdpBtpCallback callback) {
        udp_btp_callback_ = callback;
    }

protected:
    std::size_t transmit(std::unique_ptr<vanetza::ChunkPacket>);

private:
    void on_read(const boost::system::error_code&, std::size_t);
    void pass_up(vanetza::CohesivePacket&&);

    static constexpr std::size_t layers_ = num_osi_layers(vanetza::OsiLayer::Physical, vanetza::OsiLayer::Application);

    boost::asio::ip::udp::socket socket_;
    IndicationCallback callback_;
    vanetza::ByteBuffer receive_buffer_;
    boost::asio::ip::udp::endpoint receive_endpoint_;
    UdpBtpCallback udp_btp_callback_;
};

#endif /* RAW_SOCKET_LINK_HPP_VUXH507U */
