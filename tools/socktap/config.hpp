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
    string topic_test;
    string udp_out_addr;
    int udp_out_port;
    bool mqtt_enabled;
    bool mqtt_time_enabled;
    bool mqtt_test_enabled;
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
    bool rssi_enabled;
    bool mcs_enabled;
    bool ignore_own_messages;
    bool ignore_rsu_messages;
    bool enable_json_prints;
    string dds_participant_name;
    int dds_domain_id;
    int num_threads;
    bool publish_encoded_payloads;
    message_config_t cam;
    message_config_t denm;
    message_config_t cpm;
    message_config_t vam;
    message_config_t spatem;
    message_config_t mapem;
    message_config_t ssem;
    message_config_t srem;
    message_config_t rtcmem;
    message_config_t ivim;
    message_config_t imzm;
    message_config_t evcsnm;
    message_config_t evrsrm;
    message_config_t tistpgm;
    message_config_t mcm;
    string full_cam_topic_in;
    string full_cam_topic_out;
    string full_cam_topic_time;
    string full_cam_topic_test;
    string full_vam_topic_in;
    string full_vam_topic_out;
    string full_vam_topic_time;
    string full_vam_topic_test;
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
