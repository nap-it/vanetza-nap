#include "application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/imzm.hpp>

class ImzmApplication : public Application, public PubSub_application
{
public:
    ImzmApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void on_message(string, string, vanetza::geonet::Router* router);
    int priority;

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration imzm_interval_;
    PubSub* pubsub;
    config_t config_s;
    metrics_t metrics_s;

    Document buildJSON(IMZM_t imzm, double time_reception, int rssi, int packet_size);
};

