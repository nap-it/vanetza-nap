#include "router_context.hpp"
#include "application.hpp"
#include "dcc_passthrough.hpp"
#include "ethernet_device.hpp"
#include "time_trigger.hpp"
#include <vanetza/access/ethertype.hpp>
#include <vanetza/dcc/data_request.hpp>
#include <vanetza/dcc/interface.hpp>
#include <iostream>
#include <vanetza/common/byte_order.hpp>
#include <chrono>
#include <vanetza/btp/data_indication.hpp>
#include <signal.h>

#include <mutex>
#include <condition_variable>
#include <deque>

using namespace vanetza;
using namespace std::chrono;

std::vector<std::unique_ptr<vanetza::geonet::Router>> routers;

typedef struct queued_processing {
    std::shared_ptr<const vanetza::btp::DataIndication> indication; 
    vanetza::geonet::Router::UpPacketPtr packet;
} queued_processing;

class processing_thread_queue
{
private:
    std::mutex                  d_mutex;
    std::condition_variable     d_condition;
    std::deque<std::unique_ptr<queued_processing>>  d_queue[3];
public:
    processing_thread_queue() {

    }
    void push(std::unique_ptr<queued_processing> value, int priorityLevel) {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            d_queue[priorityLevel].push_front(std::move(value));
        }
        this->d_condition.notify_one();
    }
    std::unique_ptr<queued_processing> pop() {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=] {
            return !this->d_queue[0].empty() || !this->d_queue[1].empty() || !this->d_queue[2].empty();
        });
        for (int priorityLevel = 0; priorityLevel < 3; priorityLevel++) {
            if (!this->d_queue[priorityLevel].empty()) {
                std::unique_ptr<queued_processing> rc = std::move(this->d_queue[priorityLevel].back());
                this->d_queue[priorityLevel].pop_back();
                return rc;
            }
        }
        return nullptr;
    }
};

processing_thread_queue* processing_tq;

std::unordered_map<int, int> lookupTable;

typedef struct queued_reception {
    std::unique_ptr<CohesivePacket> packet;
    std::shared_ptr<const EthernetHeader> hdr;
} queued_reception;

class reception_thread_queue
{
private:
    std::mutex                  d_mutex;
    std::condition_variable     d_condition;
    std::deque<std::unique_ptr<queued_reception>>  d_queue;
public:
    reception_thread_queue() {

    }
    void push(std::unique_ptr<queued_reception> value) {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            d_queue.push_front(std::move(value));
        }
        this->d_condition.notify_one();
    }
    std::unique_ptr<queued_reception> pop() {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
        auto rc = std::move(this->d_queue.back());
        this->d_queue.pop_back();
        return rc;
    }
};

class IndicationQueue : public vanetza::btp::IndicationInterface {
public:
    void indicate(const vanetza::btp::DataIndication& indication, vanetza::geonet::Router::UpPacketPtr packet) { 
        auto copiedIndication = std::make_shared<vanetza::btp::DataIndication>(std::move(indication));
        queued_processing qp{ std::move(copiedIndication), std::move(packet) };
        processing_tq->push(std::make_unique<queued_processing>(std::move(qp)), lookupTable[indication.destination_port.get()]);
    }
};

IndicationQueue indicationQueue;
DccPassthrough* dccp = nullptr;
std::vector<std::thread> reception_threads;
std::vector<std::thread> processing_threads;
reception_thread_queue* reception_tq;
std::map<int, Application*> applications;

RouterContext::RouterContext(const geonet::MIB& mib, TimeTrigger& trigger, vanetza::PositionProvider& positioning, vanetza::security::SecurityEntity* security_entity, bool ignore_own_messages_, bool ignore_rsu_messages_, int num_threads_, boost::asio::io_service& io_context) :
    mib_(mib), trigger_(trigger), positioning_(positioning), security_entity_(security_entity), ignore_own_messages(ignore_own_messages_), ignore_rsu_messages(ignore_rsu_messages_), num_threads(num_threads_), io_context_(io_context)
{

}

RouterContext::~RouterContext()
{
    for (auto* app : applications_) {
        disable(app);
    }
}

void RouterContext::log_packet_drop(geonet::Router::PacketDropReason reason)
{
    auto reason_string = stringify(reason);
    std::cout << "Router dropped packet because of " << reason_string << " (" << static_cast<int>(reason) << ")\n";
}

void RouterContext::set_link_layer(LinkLayer* link_layer)
{
    namespace dummy = std::placeholders;

    if (link_layer) {

        dccp = new DccPassthrough { *link_layer, io_context_ };

        reception_tq = new reception_thread_queue();
        processing_tq = new processing_thread_queue();
        for(int i = 0; i < num_threads; i++) {
            reception_threads.push_back(std::thread(packet_reception_thread, i));
            std::unique_ptr<vanetza::geonet::Router> ptr = std::make_unique<vanetza::geonet::Router>(dccp->get_trigger(reception_threads[i].get_id()).runtime(), mib_);
            routers.push_back(std::move(ptr));
            routers[i]->packet_dropped = std::bind(&RouterContext::log_packet_drop, this, std::placeholders::_1);
            routers[i]->set_address(mib_.itsGnLocalGnAddr);
            routers[i]->set_transport_handler(geonet::UpperProtocol::BTP_B, &dispatcher_);
            routers[i]->set_security_entity(security_entity_);
            reception_threads[i].detach();
            processing_threads.push_back(std::thread(packet_processing_thread));
            processing_threads[i].detach();
        }
        std::unique_ptr<vanetza::geonet::Router> ptr = std::make_unique<vanetza::geonet::Router>(trigger_.runtime(), mib_);
        routers.push_back(std::move(ptr));
        routers[num_threads]->packet_dropped = std::bind(&RouterContext::log_packet_drop, this, std::placeholders::_1);
        routers[num_threads]->set_address(mib_.itsGnLocalGnAddr);
        routers[num_threads]->set_transport_handler(geonet::UpperProtocol::BTP_B, &dispatcher_);
        routers[num_threads]->set_security_entity(security_entity_);

        update_position_vector();
        dccp->get_trigger().schedule();

        request_interface_.reset(dccp);
        for(int i = 0; i < num_threads + 1; i++) {
            routers[i]->set_access_interface(request_interface_.get());
            update_packet_flow(routers[i]->get_local_position_vector());
        }
        link_layer->indicate(std::bind(&RouterContext::indicate, this, dummy::_1, dummy::_2));
    } else {
        for(int i = 0; i < num_threads + 1; i++) {
            routers[i]->set_access_interface(nullptr);
        }
        request_interface_.reset();
    }
}

void RouterContext::indicate(CohesivePacket&& packet, const EthernetHeader& hdr)
{
    if ((!ignore_own_messages || hdr.source != mib_.itsGnLocalGnAddr.mid()) && (!ignore_rsu_messages || ((int) hdr.source.octets[3]) != 0x01) && hdr.type == access::ethertype::GeoNetworking) {
        auto sharedHdr = std::make_shared<const EthernetHeader>(hdr);
        queued_reception qr{std::make_unique<CohesivePacket>(std::move(packet)), sharedHdr};
        reception_tq->push(std::make_unique<queued_reception>(std::move(qr)));
    }
}

void packet_reception_thread(int i) {
    while (true) {
        std::unique_ptr<queued_reception> qr = reception_tq->pop();
        const double time_queue = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        qr->packet.get()->time_queue = time_queue;
        std::unique_ptr<PacketVariant> up { new PacketVariant(*std::move(qr->packet)) };
        dccp->get_trigger().schedule(); // ensure the clock is up-to-date for the security entity
        routers[i]->indicate(std::move(up), qr->hdr->source, qr->hdr->destination);
        dccp->get_trigger().schedule(); // schedule packet forwarding
    }
}

void RouterContext::enable(Application* app)
{
    dispatcher_.add_promiscuous_hook(app->promiscuous_hook());
    if (app->port() != btp::port_type(0)) {
        dispatcher_.set_non_interactive_handler(app->port(), &indicationQueue);
        applications[app->port().get()] = app;
        lookupTable[app->port().get()] = app->priority;
    }
}

void RouterContext::disable(Application* app)
{
    if (app->port() != btp::port_type(0)) {
        dispatcher_.set_non_interactive_handler(app->port(), nullptr);
    }
    dispatcher_.remove_promiscuous_hook(app->promiscuous_hook());
}

void RouterContext::require_position_fix(bool flag)
{
    require_position_fix_ = flag;
    for(int i = 0; i < num_threads + 1; i++) {
        update_packet_flow(routers[i]->get_local_position_vector());
    }
}

void RouterContext::update_position_vector()
{
    for(int i = 0; i < num_threads + 1; i++) {
        routers[i]->update_position(positioning_.position_fix());
    }
    vanetza::Runtime::Callback callback = [this](vanetza::Clock::time_point) { this->update_position_vector(); };
    vanetza::Clock::duration next = std::chrono::seconds(1);
    dccp->get_trigger().runtime().schedule(next, callback);
    dccp->get_trigger().schedule();
    update_packet_flow(routers[0]->get_local_position_vector());
}

void RouterContext::update_packet_flow(const geonet::LongPositionVector& lpv)
{
    if (request_interface_) {
        if (require_position_fix_) {
            // Skip all requests until a valid GPS position is available
            request_interface_->allow_packet_flow(lpv.position_accuracy_indicator);
        } else {
            request_interface_->allow_packet_flow(true);
        }
    }
}

DccPassthrough &RouterContext::get_dccp() {
    return *(dccp);
}

void packet_processing_thread(){
    while(true) {
        std::unique_ptr<queued_processing> qp = processing_tq->pop();
        applications[qp->indication->destination_port.get()]->indicate(*std::move(qp->indication), std::move(qp->packet));
    }
}

vanetza::geonet::Router* get_router(int i) {
    return routers[i].get();
}
