#ifndef PUBSUB_HPP_PSIGPUTG
#define PUBSUB_HPP_PSIGPUTG

#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <random>
#include <variant>
#include <algorithm>
#include <unordered_set>
#include <vector>
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
#include "zenoh.hxx"

class PubSub_application
{
public:
    explicit PubSub_application(int priority_) : priority(priority_) {}
    virtual ~PubSub_application() = default;
    virtual void on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router){};
    int priority;
};

void message_transmission_thread(int i);

class PubSub {
private:
    config_t config;
    int num_threads;

    std::string append_json_obj_to_array_(std::string arr_json, const std::string& obj_json) {
        auto trim = [](std::string s){
            s.erase(0, s.find_first_not_of(" \t\n\r"));
            s.erase(s.find_last_not_of(" \t\n\r")+1);
            return s;
        };
        arr_json = trim(arr_json);
        if (arr_json.empty()) return "[" + obj_json + "]";
        if (arr_json == "null") return "[" + obj_json + "]";
        if (arr_json == "[]")   return "[" + obj_json + "]";
        if (arr_json.front() != '[' || arr_json.back() != ']') {
            return "[" + obj_json + "]";
        }
        if (arr_json.size() == 2) {
            return "[" + obj_json + "]";
        } else {
            std::string out = arr_json;
            size_t rb = out.find_last_of(']');
            out.insert(rb, "," + obj_json);
            return out;
        }
    }

    std::string get_or_empty_(zenoh::Config& cfg, const std::string& key) {
        zenoh::ZResult* err = nullptr;
        std::string v;
        try {
            v = cfg.get(key, err);
        } catch (const zenoh::ZException&) {
            v = "[]";
        }
        if (v.empty()) v = "[]";
        return v;
    }

    void put_array_(zenoh::Config& cfg, const std::string& key, const std::string& arr_json) {
        zenoh::ZResult* err = nullptr;
        cfg.insert_json5(key, arr_json, err);
        if (err && *err != 0) {
            throw std::runtime_error("Failed to put array at key: " + key);
        }
    }

    void allow_interfaces_(zenoh::Config& zconfig, const std::string& interfaces_csv) {
        auto trim = [](const std::string& value) {
            const auto first = value.find_first_not_of(" \t\n\r");
            if (first == std::string::npos) {
                return std::string();
            }
            const auto last = value.find_last_not_of(" \t\n\r");
            return value.substr(first, last - first + 1);
        };

        std::vector<std::string> interfaces;
        std::unordered_set<std::string> seen;
        auto add_interface = [&](const std::string& token) {
            auto cleaned = trim(token);
            if (cleaned.empty()) {
                return;
            }
            if (seen.insert(cleaned).second) {
                interfaces.push_back(cleaned);
            }
        };

        if (!interfaces_csv.empty()) {
            size_t start = 0;
            while (start < interfaces_csv.size()) {
                size_t comma = interfaces_csv.find(',', start);
                if (comma == std::string::npos) {
                    add_interface(interfaces_csv.substr(start));
                    break;
                }
                add_interface(interfaces_csv.substr(start, comma - start));
                start = comma + 1;
            }
        }

        if (interfaces.empty()) {
            return;
        }

        const std::string rule_id = "allow-all-on-interface";
        std::string subjects = get_or_empty_(zconfig, "access_control/subjects");
        std::string policies = get_or_empty_(zconfig, "access_control/policies");

        for (const auto& ifname : interfaces) {
            const std::string subj_id = "iface-" + ifname;
            const std::string pol_id = "policy-" + ifname;

            const std::string subject = std::string("{")
                + "\"id\":\"" + subj_id + "\","
                + "\"interfaces\":[\"" + ifname + "\"]"
                + "}";

            const std::string policy = std::string("{")
                + "\"id\":\"" + pol_id + "\","
                + "\"rules\":[\"" + rule_id + "\"],"
                + "\"subjects\":[\"" + subj_id + "\"]"
                + "}";

            subjects = append_json_obj_to_array_(subjects, subject);
            policies = append_json_obj_to_array_(policies, policy);
        }

        put_array_(zconfig, "access_control/subjects", subjects);
        put_array_(zconfig, "access_control/policies", policies);
    }

public:
    PubSub(config_t config_, int num_threads_, std::mutex& prom_mtx_);
    ~PubSub();
    void publish_encoded(message_config_t message_config, const std::vector<uint8_t>& payload, int16_t rssi, bool newInfo, int16_t packetSize, int32_t stationID, int32_t receiverID, int16_t receiverType, double timestamp, string test);
    void publish(message_config_t message_config, rapidjson::Document& message_json, boost::asio::ip::udp::socket* udp_socket, boost::asio::ip::udp::endpoint* remote_endpoint, boost::system::error_code* err, prometheus::Counter* counter, prometheus::Counter* latency, double time_received, double time_encoded, double time_queue, double time_queue2, std::string message_type);
    void publish_time(message_config_t message_config, rapidjson::Value& message_json);
    void subscribe(message_config_t message_config, PubSub_application* app);
    void manual_provision(message_config_t message_config, std::string topic);
    void declare_zenoh_publisher(message_config_t message_config, std::string topic);
    void manual_subscribe(message_config_t message_config, std::string topic, PubSub_application* app);
    void on_message(std::string topic, std::string message, int priority);
    void on_message(std::string topic, const std::vector<uint8_t>& message, int priority, std::string test);

    Mqtt* local_mqtt;
    Mqtt* remote_mqtt;
    Dds* dds;
    zenoh::Session* session = nullptr;
    zenoh::PosixShmProvider* shm_provider = nullptr;
    std::mutex& prom_mtx;
};

#endif /* PUBSUB_HPP_PSIGPUTG */
