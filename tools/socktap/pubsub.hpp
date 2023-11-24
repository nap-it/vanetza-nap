#ifndef PUBSUB_HPP_PSIGPUTG
#define PUBSUB_HPP_PSIGPUTG

#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <prometheus/counter.h>
#include <boost/asio.hpp>
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
    virtual void on_message(std::string, std::string){};
};

void message_transmission_thread(int i);

class PubSub {
private:
    Mqtt local_mqtt;
    Mqtt remote_mqtt;
    Dds dds;
    std::map<std::string, PubSub_application*> subscribers;
    config_t config;
public:
    PubSub(config_t config_, Mqtt* local_mqtt_, Mqtt* remote_mqtt_, Dds* dds_);
    ~PubSub();
    void publish(message_config_t message_config, Document message_json, boost::asio::ip::udp::socket* udp_socket, ip::udp::endpoint* remote_endpoint, boost::system::error_code* err; prometheus::Counter* counter, prometheus::Counter* latency, double time_received, std::string message_type);
    void publish_time(message_config_t message_config, Document message_json);
    void subscribe(message_config_t message_config, PubSub_application* app, int priority);
    void on_message(std::string topic, std::string message, int priority);
};

#endif /* PUBSUB_HPP_PSIGPUTG */