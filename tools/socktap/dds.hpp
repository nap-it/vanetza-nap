#ifndef DDS_HPP_PSIGPUTG
#define DDS_HPP_PSIGPUTG

#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <thread>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "time_trigger.hpp"
#include "config.hpp"

#include "fastdds/DDSSubscriber.hpp"
#include "fastdds/DDSPublisher.hpp"

#include "fastdds/MQTTMessagePubSubTypes.h"
#include "fastdds/EncodedITSMessagePubSubTypes.h"

using namespace std;

class PubSub;

class Dds {
private:
    void from_dds_thread();
    PubSub* pubsub;
    eprosima::fastrtps::fixed_string<255> participantName;
    DomainId_t domain_id;

public:
    Dds(PubSub* pubsub_, config_t config);
    ~Dds();
    void publish(string topic, string message);
    void publish(string topic, const std::vector<uint8_t>& payload, int16_t rssi, bool newInfo, int16_t packetSize, int32_t stationID, int32_t receiverID, int16_t receiverType, double timestamp, string test);
    void provison_publisher(string topic);
    void subscribe(string topic);
    void on_message(string topic, string message);
    void on_message(string topic, const std::vector<uint8_t>& payload, string test);
};

#endif /* DDS_HPP_PSIGPUTG */
