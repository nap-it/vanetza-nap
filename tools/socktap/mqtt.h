#include <mosquittopp.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "time_trigger.hpp"

#define TAG "mqtt.cpp: "

using namespace std;

class Mqtt_client
{
public:
    virtual void on_message(string, string){};
};


/**
 * @class Mqtt
 * This class is responsible for the mqtt connection using mosquittopp.
 */
class Mqtt : public mosqpp::mosquittopp {
private:
    string id;
    string host;
    int port;
    map<string, Mqtt_client*> subscribers;


    /**
     * the number of seconds after which the broker should send a PING message to the client if no other messages have
     * been exchanged in that time
     */
    int keepalive;

    void on_connect(int rc);

    void on_disconnect(int rc);

    void on_publish(int mid);

    void on_subscribe(int /*mid*/, int /*qos_count*/, const int */*granted_qos*/);

    /**
     * @brief callback function
     *
     * callback function that is called when a new message is received
     *
     * @param message structure that contains the message as payload, among other things
     */
    void on_message(const struct mosquitto_message *message);

public:
    /**
     * @brief Mqtt constructor
     *
     * constructor of the class when a login to the server is required.
     *
     * @param id
     * @param host the hostname or ip address of the broker to connect to
     * @param port the network port to connect to (usually 1883)
     * @param username username, if expected by the server
     * @param password password, if expected by the server
     */
    Mqtt(string id, string host, int port, string username, string password);

    /**
     * @brief Mqtt constructor
     *
     * constructor of the class when a login to the server is not required.
     *
     * @param id
     * @param host the hostname or ip address of the broker to connect to
     * @param port the network port to connect to (usually 1883)
     */
    Mqtt(string id, string host, int port);

    ~Mqtt();

    /**
     * @brief publish a message on a given topic
     * @param message null terminated string of the topic to publish to
     * @return True, if publication was successfully
     */
    bool publish(string topic, string message);

    /**
     * @brief subscribe to a topic
     * @return True, if subscription was successfully
     */
    bool subscribe(string topic, Mqtt_client* object);
};


