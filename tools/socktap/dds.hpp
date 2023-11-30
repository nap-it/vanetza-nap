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

#include "fastdds/DDSSubscriber.hpp"
#include "fastdds/DDSPublisher.hpp"

#include "fastdds/MQTTMessagePubSubTypes.h"

using namespace std;

class PubSub;

class Dds {
private:
    void from_dds_thread();
    PubSub* pubsub;

public:
    Dds(int to_dds_port, int from_dds_port, PubSub* pubsub_);
    ~Dds();
    void publish(string topic, string message);
    void provison_publisher(string topic);
    void subscribe(string topic);
    void on_message(string topic, string message);
};

#endif /* DDS_HPP_PSIGPUTG */
