#include "pubsub.hpp"

using namespace std::chrono;

typedef struct queued_transmission {
    std::string topic; 
    std::string message;
} queued_transmission;

class transmission_thread_queue
{
private:
    std::mutex                  d_mutex;
    std::condition_variable     d_condition;
    int num_queues = 2 * 3; 
    std::deque<queued_transmission*>  d_queue[this->num_queues];
public:
    transmission_thread_queue() {

    }
    void push(queued_transmission* value, int priorityLevel) {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            d_queue[priorityLevel].push_front(value);
        }
        this->d_condition.notify_one();
    }
    queued_transmission* pop() {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=] {
            for(int i = 0; i < this->num_queues; i++) {
                if (!this->d_queue[i].empty()) return true;
            }
            return false;
        });
        for (int priorityLevel = 0; priorityLevel < num_queues; priorityLevel++) {
            if (!this->d_queue[priorityLevel].empty()) {
                queued_transmission* rc = std::move(this->d_queue[priorityLevel].back());
                this->d_queue[priorityLevel].pop_back();
                return rc;
            }
        }
    }
};

transmission_thread_queue* transmission_tq;
std::vector<std::thread> transmission_threads;
std::unordered_map<std::string, int> lookupTable;


PubSub::PubSub(config_t config_, Mqtt* local_mqtt_, Mqtt* remote_mqtt_, Dds* dds_) 
    config(config_), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_)
{
    for(int i = 0; i < num_threads; i++) {
        transmission_threads.push_back(std::thread(message_transmission_thread, i));
        transmission_threads[i].detach();
    }
}

PubSub::~PubSub() {
    // TODO: Call MQTT & DDS Destructors
}

void PubSub::on_message(std::string topic, std::string message, int priority) {
    queued_transmission qt{topic, message};
    transmission_tq->push(&qt, lookupTable[topic] + (3 * priority));
}

void PubSub::subscribe(message_config_t message_config, PubSub_application* app, int priority) {
    std::string topic = config.topic_in;
    this->subscribers[topic] = app;
    lookupTable[topic] = priority;
    if(config.dds_enabled) this->dds.subscribe(topic);
    if(config.mqtt_enabled) {
        this->local_mqtt.subscribe(topic);
        if(this->remote_mqtt != NULL) this->remote_mqtt.subscribe(topic);
    }
}

void PubSub::publish(message_config_t message_config, Document message_json, boost::asio::ip::udp::socket* udp_socket, ip::udp::endpoint* remote_endpoint, boost::system::error_code* err; prometheus::Counter* counter, prometheus::Counter* latency, double time_received, std::string message_type) {
    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    message_json.Accept(writer);
    const char* messageJSON = fullBuffer.GetString();

    if(message_config.udp_out_port != 0) {
        udp_socket->send_to(buffer(messageJSON, strlen(messageJSON)), remote_endpoint, 0, err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(message_config.dds_enabled) this->dds->publish(message_config.topic_out, messageJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(message_config.mqtt_enabled) this->local_mqtt->publish(message_config.topic_out, messageJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(message_config.mqtt_enabled && this->remote_mqtt != NULL) this->remote_mqtt->publish(this->config.remote_mqtt_prefix + std::to_string(this->config.station_id) + "/" + message_config.topic_out, messageJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    
    counter->Increment();
    latency->Increment(time_full_remote - time_received);

    if(message_config.mqtt_test_enabled) {
        Document::AllocatorType& allocator = message_json.GetAllocator();
        if (message_config.udp_out_port != 0) message_json["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
        if (message_config.dds_enabled != 0) message_json["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
        if (message_config.mqtt_enabled != 0) message_json["test"].AddMember("full_local_timestamp", time_full_local, allocator);
        if (message_config.mqtt_enabled && this->remote_mqtt != NULL) message_json["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);

        StringBuffer testBuffer;
        Writer<StringBuffer> testWriter(testBuffer);
        message_json.Accept(testWriter);
        const char* testJSON = testBuffer.GetString();
        this->local_mqtt->publish(message_config.topic_test, testJSON);
        if(this->remote_mqtt != NULL) remote_mqtt->publish(this->config.remote_mqtt_prefix + std::to_string(this->config.station_id) + "/" + message_config.topic_test, testJSON);
    }

    if(config.enable_json_prints) std::cout << message_type << " JSON: " << messageJSON << std::endl;
}

void publish_time(message_config_t message_config, Document message_json) {
    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    message_json.Accept(writer);
    const char* messageJSON = fullBuffer.GetString();

    this->local_mqtt->publish(message_config.topic_time, messageJSON);
    if (this->remote_mqtt != NULL) this->remote_mqtt->publish(this->config.remote_mqtt_prefix + std::to_string(this->config.station_id) + "/" + message_config.topic_time, messageJSON);
}

void message_transmission_thread(int i) {
    while (true){
        queued_transmission* qt = transmission_tq->pop();
        this->subscribers[qt->topic]->on_message(qt->topic, qt->message, std::move(routers[i]));
    }
}

