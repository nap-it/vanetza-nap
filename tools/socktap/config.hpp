#include "config_reader.hpp"
#include <iostream>
#include <prometheus/counter.h>
#include <prometheus/registry.h>

#ifndef CONFIG_H_
#define CONFIG_H_

using namespace std;

typedef struct message_config {
    bool enabled;
    int periodicity;
    string topic_in;
    string topic_out;
    string udp_out_addr;
    int udp_out_port;
} message_config_t;

typedef struct config {
    int StationID;
    int StationType;
    string mac_address;
    bool use_hardcoded_gps;
    double latitude;
    double longitude;
    string interface;
    string mqtt_broker;
    int mqtt_port;
    int prometheus_port;
    int rssi_port;
    bool ignore_own_messages;
    message_config_t cam;
    message_config_t denm;
    message_config_t cpm;
    message_config_t vam;
    message_config_t spatem;
    message_config_t mapem;
    string full_cam_topic_out;
} config_t;

typedef struct metrics {
    std::shared_ptr<prometheus::Registry> registry;
    prometheus::Family<prometheus::Counter> *packet_counter;
    prometheus::Family<prometheus::Counter> *latency_counter;
    prometheus::Family<prometheus::Counter> *error_counter;
} metrics_t;

message_config_t read_message_config(INIReader reader, string env_prefix, string ini_section);
void read_config(config_t* config_s, string path);

#endif