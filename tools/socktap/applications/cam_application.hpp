#ifndef CAM_APPLICATION_HPP_EUIC2VFR
#define CAM_APPLICATION_HPP_EUIC2VFR

#include "../application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/cam.hpp>
#include <math.h> 

class CamApplication : public Application, public PubSub_application
{
public:
    CamApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, vanetza::geonet::Router* timer_router_, int priority_, std::mutex& prom_mtx_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router);
    int priority;

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);

    vanetza::PositionProvider& positioning_;
    vanetza::Runtime& runtime_;
    vanetza::Clock::duration cam_interval_;
    PubSub* pubsub;
    std::mutex& prom_mtx;
    config_t config_s;
    metrics_t metrics_s;
    vanetza::geonet::Router* timer_router;

    Document buildJSON(CAM_t cam, Document& cam_json_full, double time_reception, double time_queue, int rssi, int packet_size, channel channel_info, bool include_fields, bool rx, bool full, string source);

    bool isNewInfo(long stationID, long latitude, long longitude, double speed, long heading, double time_reception);
    long double calcDistance(long double lat1, long double long1, long double lat2, long double long2);
    long double toRadians(const long double & degree);

};

#endif /* CAM_APPLICATION_HPP_EUIC2VFR */
