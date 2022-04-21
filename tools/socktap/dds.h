#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <thread>
#include "mqtt.h"

using namespace std;

class Dds {
private:
    void on_message(string topic, string message);
    void start_receive();
    void handle_receive(const boost::system::error_code& error,
                       std::size_t bytes_transferred);

    boost::asio::ip::udp::socket from_dds_udp_socket;

public:
    Dds(int to_dds_port, int from_dds_port);
    ~Dds();
    bool publish(string topic, string message);
    bool subscribe(string topic, Mqtt_client* object);
};

void from_dds_thread();

