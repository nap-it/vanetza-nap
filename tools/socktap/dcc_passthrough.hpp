#ifndef DCC_PASSTHROUGH_HPP_GSDFESAE
#define DCC_PASSTHROUGH_HPP_GSDFESAE

#include "time_trigger.hpp"
#include <vanetza/access/interface.hpp>
#include <vanetza/dcc/data_request.hpp>
#include <vanetza/dcc/interface.hpp>
#include <vanetza/net/cohesive_packet.hpp>

class DccPassthrough : public vanetza::dcc::RequestInterface
{
public:
    DccPassthrough(vanetza::access::Interface&, boost::asio::io_context&);

    void request(const vanetza::dcc::DataRequest& request, std::unique_ptr<vanetza::ChunkPacket> packet) override;

    void allow_packet_flow(bool allow);
    bool allow_packet_flow();
    TimeTrigger& get_trigger();

private:
    vanetza::access::Interface& access_;
    boost::asio::io_context& io_context_;
    bool allow_packet_flow_ = true;
};

#endif /* DCC_PASSTHROUGH_HPP_GSDFESAE */
