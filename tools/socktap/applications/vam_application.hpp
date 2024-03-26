#include "../application.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <vanetza/asn1/vam.hpp>

class VamApplication : public Application, public PubSub_application
{
public:
    VamApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_, std::mutex& prom_mtx_);
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
    vanetza::Clock::duration vam_interval_;
    PubSub* pubsub;
    std::mutex& prom_mtx;
    config_t config_s;
    metrics_t metrics_s;

    Document buildJSON(VAM_t vam, Document& vam_json_full, double time_reception, int rssi, int packet_size, double time_queue, channel channel_info);

    bool isNewInfo(long stationID, long latitude, long longitude, double speed, long heading, double time_reception);
    bool isNewInfo(long stationID, double time_reception);
    long double calcDistance(long double lat1, long double long1, long double lat2, long double long2);
    long double toRadians(const long double & degree);
};

