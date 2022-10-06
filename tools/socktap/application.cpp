#include "application.hpp"
#include <vanetza/btp/header.hpp>
#include <vanetza/btp/header_conversion.hpp>
#include <cassert>

#include <mutex>
#include <condition_variable>
#include <deque>

using namespace vanetza;

void initialize_request(const Application::DataRequest& generic, geonet::DataRequest& geonet)
{
    geonet.upper_protocol = geonet::UpperProtocol::BTP_B;
    geonet.communication_profile = generic.communication_profile;
    geonet.its_aid = generic.its_aid;
    if (generic.maximum_lifetime) {
        geonet.maximum_lifetime = generic.maximum_lifetime.get();
    }
    geonet.repetition = generic.repetition;
    geonet.traffic_class = generic.traffic_class;
}

static geonet::GbcDataRequest request_gbc(const vanetza::btp::DataRequestGeoNetParams& generic, vanetza::geonet::Router* router)
{
    assert(router);
    geonet::GbcDataRequest gbc(router->get_mib());
    initialize_request(generic, gbc);
    gbc.destination = boost::get<geonet::Area>(generic.destination);
    return gbc;
}

static geonet::ShbDataRequest request_shb(const vanetza::btp::DataRequestGeoNetParams& generic, vanetza::geonet::Router* router)
{
    assert(router);
    geonet::ShbDataRequest shb(router->get_mib());
    initialize_request(generic, shb);
    return shb;
}

Application::PromiscuousHook* Application::promiscuous_hook()
{
    return nullptr;
}

typedef struct queued_request {
    const vanetza::btp::DataRequestGeoNetParams& request;
    vanetza::geonet::Router::DownPacketPtr* packet;
    std::condition_variable* condition;
    vanetza::geonet::DataConfirm* confirm;
    vanetza::geonet::Router* router;
    std::mutex*  mutex;
    bool done;
} queued_request;

class thread_queue
{
private:
    std::mutex                  d_mutex;
    std::condition_variable     d_condition;
    std::deque<queued_request*>  d_queue;
public:
    thread_queue() {

    }
    vanetza::geonet::DataConfirm* push(queued_request* value) {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            d_queue.push_front(value);
        }
        this->d_condition.notify_one();
        std::unique_lock<std::mutex> lock2(*(value->mutex));
        value->condition->wait(lock2, [=]{ return value->done; });
        return value->confirm;
    }
    queued_request* pop() {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
        queued_request* rc(std::move(this->d_queue.back()));
        this->d_queue.pop_back();
        return rc;
    }
};

thread_queue* q;

Application::DataConfirm Application::request(const DataRequest& request, DownPacketPtr packet)
{
    std::condition_variable condition;
    std::mutex  mutex;
    btp::HeaderB btp_header;
    btp_header.destination_port = this->port();
    btp_header.destination_port_info = host_cast<uint16_t>(0);
    packet->layer(OsiLayer::Transport) = btp_header;
    queued_request qr{request, &packet, &condition, nullptr, router_, &mutex, false};
    return *(q->push(&qr));
}

void application_thread() {
    q = new thread_queue();
    while (true) {
        queued_request* qr = q->pop();
        vanetza::geonet::DataConfirm confirm(vanetza::geonet::DataConfirm::ResultCode::Rejected_Unspecified);
        if (qr->router && qr->packet) {
            switch (qr->request.transport_type) {
                case geonet::TransportType::SHB:
                    confirm = qr->router->request(request_shb(qr->request, qr->router), std::move(*(qr->packet)));
                    break;
                case geonet::TransportType::GBC:
                    confirm = qr->router->request(request_gbc(qr->request, qr->router), std::move(*(qr->packet)));
                    break;
                default:
                    // TODO remaining transport types are not implemented
                    break;
            }
        }
        qr->confirm = &(confirm);
        qr->done = true;
        qr->condition->notify_one();
    }
}

void start_application_thread()
{
  std::thread t1(application_thread);
  t1.detach();
}
