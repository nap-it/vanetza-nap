#ifndef CAM_APPLICATION_HPP_EUIC2VFR
#define CAM_APPLICATION_HPP_EUIC2VFR

#include "application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/cam.hpp>

class CamApplication : public Application, public Mqtt_client
{
public:
    CamApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, Mqtt* mqtt_, std::shared_ptr<prometheus::Registry>* registry_, prometheus::Family<prometheus::Counter>* packet_counter_, prometheus::Family<prometheus::Counter>* latency_counter_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void print_received_message(bool flag);
    void print_generated_message(bool flag);
    void on_message(string);
    void send(vanetza::asn1::Cam message);

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration cam_interval_;
    bool print_rx_msg_ = false;
    bool print_tx_msg_ = false;

    std::string buildJSON(vanetza::asn1::Cam cam, int rssi);
};

#endif /* CAM_APPLICATION_HPP_EUIC2VFR */
