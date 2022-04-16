#ifndef DENM_APPLICATION_HPP_EUIC2VFR
#define DENM_APPLICATION_HPP_EUIC2VFR

#include "application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/denm.hpp>

class DenmApplication : public Application, public Mqtt_client
{
public:
    DenmApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, Mqtt* mqtt_, config_t config_s_, metrics_t metrics_s_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void on_message(string);

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration denm_interval_;
    Mqtt *mqtt;
    config_t config_s;
    metrics_t metrics_s;

    std::string buildJSON(DENM_t denm, double time_reception, int rssi);
};

#endif /* DENM_APPLICATION_HPP_EUIC2VFR */
