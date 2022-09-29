#include "mqtt.h"
#include <map>  



Mqtt::Mqtt(string id, string host, int port, string username, string password){

    mosqpp::lib_init();
    this->id = id;
    this->keepalive = 60;
    this->port = port;
    this->host = host;

    mosquittopp::username_pw_set(username.c_str(), password.c_str());


    /*
     * Connect to an MQTT broker. This is a non-blocking call. If you use mosquitto_connect_async your client must use
     * the threaded interface mosquitto_loop_start.
     */
    connect_async(this->host.c_str(), this->port, this->keepalive);
    loop_start();

}



Mqtt::Mqtt(string id, string host, int port) : mosquittopp(id.c_str())
{
    mosqpp::lib_init();
    this->id = id;
    this->keepalive = 60;
    this->port = port;
    this->host = host;


    /*
     * Connect to an MQTT broker. This is a non-blocking call. If you use mosquitto_connect_async your client must use
     * the threaded interface mosquitto_loop_start.
     */
    connect_async(this->host.c_str(), this->port, this->keepalive);
    loop_start();
};

Mqtt::~Mqtt() {
    disconnect();
    loop_stop();
    mosqpp::lib_cleanup();
}

bool Mqtt::publish(string topic, string message)
{
    /*
     * NULL: pointer to an int.  If not NULL, the function will set this to the message id of this particular message.
     * This can be then used with the publish callback to determine when the message has been sent.
     * Note that although the MQTT protocol doesn’t use message ids for messages with QoS=0, libmosquitto assigns them
     * message ids so they can be tracked with this parameter.
     *
     * publish_topic.c_str(): null terminated string of the topic to publish to.
     *
     * message.length(): the size of the payload (bytes). Valid values are between 0 and 268,435,455.
     *
     * message.c_str(): pointer to the data to send.  If message.length() > 0 this must be a valid memory location.
     *
     * 1: integer value 0, 1 or 2 indicating the Quality of Service to be used for the message.
     *
     * false: set to true to make the message retained.
     *
     */
    int answer = mosqpp::mosquittopp::publish(nullptr, topic.c_str(), message.length(), message.c_str(), 1, false);
    return (answer == MOSQ_ERR_SUCCESS);
}

bool Mqtt::subscribe(string topic, Mqtt_client* object) {
    this->subscribers[topic] = object;
    int answer = mosquittopp::subscribe(nullptr, topic.c_str());
    return answer == MOSQ_ERR_SUCCESS;
}

void Mqtt::on_subscribe(int, int, const int *) {
    cout << TAG <<"Subscription succeeded." << endl;
}

void Mqtt::on_message(const struct mosquitto_message *message) {

    string payload = string(static_cast<char *>(message->payload));
    string topic = string(message->topic);

    this->subscribers[topic]->on_message(topic, payload);

    //cout<< TAG << "payload: " << payload << endl;
    //cout<< TAG << "topic: " << topic << endl;
}

void Mqtt::on_disconnect(int rc) {
    cout << TAG << "disconnection(" << rc << ")" << endl;
}

void Mqtt::on_connect(int rc)
{
    if ( rc == 0 ) {
        cout << TAG << "connected with server" << endl;
        if (this->subscribers.size() > 0) {
            for ( const auto &sub : this->subscribers ) {
                this->subscribe(sub.first, this->subscribers[sub.first]);
            }
        }
    } else {
        cout << TAG << "impossible to connect with server(" << rc << ")" << endl;
    }
}

void Mqtt::on_publish(int mid)
{
    //cout << TAG << "Message (" << mid << ") succeed to be published " << endl;
}
