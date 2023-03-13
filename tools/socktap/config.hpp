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
    string topic_time;
    string udp_out_addr;
    int udp_out_port;
    bool mqtt_enabled;
    bool mqtt_time_enabled;
    bool dds_enabled;
} message_config_t;

typedef struct config {
    int station_id;
    int station_type;
    string remote_mqtt_prefix;
    string mac_address;
    bool beacons_enabled;
    bool use_hardcoded_gps;
    double latitude;
    double longitude;
    double length;
    double width;
    string interface;
    string local_mqtt_broker;
    int local_mqtt_port;
    string remote_mqtt_broker;
    int remote_mqtt_port;
    string remote_mqtt_username;
    string remote_mqtt_password;
    string gpsd_host;
    string gpsd_port;
    int prometheus_port;
    int rssi_enabled;
    bool ignore_own_messages;
    bool ignore_rsu_messages;
    int to_dds_key;
    int from_dds_key;
    bool enable_json_prints;
    message_config_t cam;
    message_config_t denm;
    message_config_t cpm;
    message_config_t vam;
    message_config_t spatem;
    message_config_t mapem;
    string full_cam_topic_in;
    string full_cam_topic_out;
    string full_vam_topic_in;
    string full_vam_topic_out;
    string own_cam_topic_out;
    string own_full_cam_topic_out;
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
