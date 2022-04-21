#include "dds.h"
#include <map>

using namespace boost::asio;

map<string, Mqtt_client*> dds_subscribers;

boost::asio::io_service to_dds_io_service_;
ip::udp::socket to_dds_udp_socket(to_dds_io_service_);
ip::udp::endpoint to_dds_remote_endpoint;
boost::system::error_code to_dds_err;

boost::asio::io_service from_dds_io_service_;
ip::udp::endpoint from_dds_remote_endpoint;
std::array<char, 9999> from_dds_buffer;

Dds::Dds(int to_dds_port, int from_dds_port)
    : from_dds_udp_socket(from_dds_io_service_, ip::udp::endpoint(ip::udp::v4(), from_dds_port)) {
    to_dds_udp_socket.open(ip::udp::v4());
    to_dds_remote_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), to_dds_port);
    
    std::thread dds_th(from_dds_thread);
    dds_th.detach();
    start_receive();
}

Dds::~Dds() {

}

void Dds::start_receive() {
    from_dds_udp_socket.async_receive_from(
        boost::asio::buffer(from_dds_buffer), from_dds_remote_endpoint,
        boost::bind(&Dds::handle_receive, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Dds::handle_receive(const boost::system::error_code& error,
                       std::size_t bytes_transferred) {
    if (!error || error == boost::asio::error::message_size) {
        string data(from_dds_buffer.data());
        std::string::size_type pos = data.find(';');
        if (pos != std::string::npos)
        {
            on_message(data.substr(0,pos), data.substr(pos+1, data.length()));
        }
    }
    start_receive();
}

bool Dds::publish(string topic, string message)
{
    string buf = topic + ";" + message;
    to_dds_udp_socket.send_to(buffer(buf, buf.length()), to_dds_remote_endpoint, 0, to_dds_err);
    return true;
}

bool Dds::subscribe(string topic, Mqtt_client* object) {
    dds_subscribers[topic] = object;
    return true;
}

void from_dds_thread() {
    from_dds_io_service_.run();
}

void Dds::on_message(string topic, string message) {
    if(dds_subscribers[topic] != nullptr) {
        dds_subscribers[topic]->on_message(topic, message);
    }
}