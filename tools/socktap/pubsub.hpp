#ifndef PUBSUB_HPP_PSIGPUTG
#define PUBSUB_HPP_PSIGPUTG

#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <random>
#include <prometheus/counter.h>
#include <boost/asio.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/asio/ip/host_name.hpp>
#include "mqtt.h"
#include "dds.h"
#include "router_context.hpp"
#include "config.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class PubSub_application
{
public:
    virtual void on_message(std::string, std::string, vanetza::geonet::Router* router){};
    int priority;
};

void message_transmission_thread(int i);

class PubSub {
private:
    config_t config;
    int num_threads;
public:
    PubSub(config_t config_, int num_threads_);
    ~PubSub();
    void publish(message_config_t message_config, rapidjson::Document& message_json, boost::asio::ip::udp::socket* udp_socket, boost::asio::ip::udp::endpoint* remote_endpoint, boost::system::error_code* err, prometheus::Counter* counter, prometheus::Counter* latency, double time_received, std::string message_type);
    void publish_time(message_config_t message_config, rapidjson::Value& message_json);
    void subscribe(message_config_t message_config, PubSub_application* app);
    void manual_subscribe(message_config_t message_config, std::string topic, PubSub_application* app);
    void on_message(std::string topic, std::string message, int priority);

    Mqtt* local_mqtt;
    Mqtt* remote_mqtt;
    Dds* dds;
};

#endif /* PUBSUB_HPP_PSIGPUTG */