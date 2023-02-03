#include "application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/mapem.hpp>

class MapemApplication : public Application, public Mqtt_client
{
public:
    MapemApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void on_message(string, string);

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration mapem_interval_;
    Mqtt *local_mqtt;
    Mqtt *remote_mqtt;
    Dds *dds;
    config_t config_s;
    metrics_t metrics_s;

    std::string buildJSON(MAPEM_t spatem, double time_reception, int rssi, int packet_size) ;
};

