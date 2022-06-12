#include "dcc_passthrough.hpp"
#include "time_trigger.hpp"
#include <vanetza/access/data_request.hpp>
#include <vanetza/dcc/data_request.hpp>
#include <vanetza/dcc/interface.hpp>
#include <vanetza/dcc/mapping.hpp>
#include <vanetza/net/chunk_packet.hpp>
#include <iostream>
#include <thread>

using namespace vanetza;

std::map<std::thread::id, TimeTrigger*> triggers_;

DccPassthrough::DccPassthrough(access::Interface& access, boost::asio::io_context& io_context) :
        access_(access), io_context_(io_context) {}


void DccPassthrough::request(const dcc::DataRequest& request, std::unique_ptr<ChunkPacket> packet)
{
    if (!allow_packet_flow_) {
        std::cout << "ignored request because packet flow is suppressed\n";
        return;
    }

    get_trigger().schedule();

    access::DataRequest acc_req;
    acc_req.ether_type = request.ether_type;
    acc_req.source_addr = request.source;
    acc_req.destination_addr = request.destination;
    acc_req.access_category = dcc::map_profile_onto_ac(request.dcc_profile);
    access_.request(acc_req, std::move(packet));
}

void DccPassthrough::allow_packet_flow(bool allow)
{
    allow_packet_flow_ = allow;
}

bool DccPassthrough::allow_packet_flow()
{
    return allow_packet_flow_;
}

TimeTrigger &DccPassthrough::get_trigger() {
    std::thread::id curr_id = std::this_thread::get_id();
    if (!triggers_.count(curr_id)) {
        triggers_[curr_id] = new TimeTrigger(io_context_);
    }
    return *(triggers_[curr_id]);
}
