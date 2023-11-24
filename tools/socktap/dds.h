#ifndef DDS_HPP_PSIGPUTG
#define DDS_HPP_PSIGPUTG

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <thread>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "time_trigger.hpp"

using namespace std;

class PubSub;

class Dds {
private:
    void on_message(string topic, string message);
    void from_dds_thread();
    PubSub* pubsub;

public:
    Dds(int to_dds_port, int from_dds_port, PubSub* pubsub_);
    ~Dds();
    bool publish(string topic, string message);
    bool subscribe(string topic);
};

#endif /* DDS_HPP_PSIGPUTG */
