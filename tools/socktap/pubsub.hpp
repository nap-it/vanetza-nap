#ifndef PUBSUB_HPP_PSIGPUTG
#define PUBSUB_HPP_PSIGPUTG

#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <random>
#include <variant>
#include <prometheus/counter.h>
#include <boost/asio.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/asio/ip/host_name.hpp>
#include "mqtt.hpp"
#include "dds.hpp"
#include "router_context.hpp"
#include "config.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class PubSub_application
{
public:
    virtual void on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router){};
    int priority;
};

void message_transmission_thread(int i);

class PubSub {
private:
    config_t config;
    int num_threads;
public:
    PubSub(config_t config_, int num_threads_, std::mutex& prom_mtx_);
    ~PubSub();
    void publish_encoded(message_config_t message_config, const std::vector<uint8_t>& payload, int16_t rssi, bool newInfo, int16_t packetSize, int32_t stationID, int32_t receiverID, int16_t receiverType, double timestamp, string test);
    void publish(message_config_t message_config, rapidjson::Document& message_json, boost::asio::ip::udp::socket* udp_socket, boost::asio::ip::udp::endpoint* remote_endpoint, boost::system::error_code* err, prometheus::Counter* counter, prometheus::Counter* latency, double time_received, double time_encoded, double time_queue, double time_queue2, std::string message_type);
    void publish_time(message_config_t message_config, rapidjson::Value& message_json);
    void subscribe(message_config_t message_config, PubSub_application* app);
    void manual_provision(message_config_t message_config, std::string topic);
    void manual_subscribe(message_config_t message_config, std::string topic, PubSub_application* app);
    void on_message(std::string topic, std::string message, int priority);
    void on_message(std::string topic, const std::vector<uint8_t>& message, int priority, std::string test);

    Mqtt* local_mqtt;
    Mqtt* remote_mqtt;
    Dds* dds;
    std::mutex& prom_mtx;
};

#endif /* PUBSUB_HPP_PSIGPUTG */