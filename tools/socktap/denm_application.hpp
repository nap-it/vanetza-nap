#ifndef DENM_APPLICATION_HPP_EUIC2VFR
#define DENM_APPLICATION_HPP_EUIC2VFR

#include "application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/denm.hpp>

class DenmApplication : public Application
{
public:
    DenmApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void print_received_message(bool flag);
    void print_generated_message(bool flag);

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration denm_interval_;
    bool print_rx_msg_ = false;
    bool print_tx_msg_ = false;

    std::string buildJSON(vanetza::asn1::Denm denm);
};

#endif /* DENM_APPLICATION_HPP_EUIC2VFR */
