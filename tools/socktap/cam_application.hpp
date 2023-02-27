#ifndef CAM_APPLICATION_HPP_EUIC2VFR
#define CAM_APPLICATION_HPP_EUIC2VFR

#include "application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/cam.hpp>
#include <math.h> 

class CamApplication : public Application, public Mqtt_client
{
public:
    CamApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void on_message(string, string);

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration cam_interval_;
    Mqtt *local_mqtt;
    Mqtt *remote_mqtt;
    Dds *dds;
    config_t config_s;
    metrics_t metrics_s;

    std::string buildJSON(CAM_t cam, std::string & cam_json_full, double time_reception, int rssi, int packet_size, bool include_fields, bool rx, bool full);

    bool isNewInfo(long stationID, long latitude, long longitude, double speed, long heading, double time_reception);
    long double calcDistance(long double lat1, long double long1, long double lat2, long double long2);
    long double toRadians(const long double & degree);

};

#endif /* CAM_APPLICATION_HPP_EUIC2VFR */
