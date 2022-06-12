#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <thread>
#include "mqtt.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include "time_trigger.hpp"

using namespace std;

class Dds {
private:
    void on_message(string topic, string message);
    void from_dds_thread();

public:
    Dds(int to_dds_port, int from_dds_port);
    ~Dds();
    bool publish(string topic, string message);
    bool subscribe(string topic, Mqtt_client* object);
};

