#include "pubsub.hpp"

using namespace std::chrono;
using namespace rapidjson;

typedef struct queued_transmission {
    std::string topic; 
    std::string message; 
    std::vector<uint8_t> payload;
    bool is_encoded;
    const double time_reception;
    std::string test;
} queued_transmission;

class transmission_thread_queue
{
private:
    std::mutex                  d_mutex;
    std::condition_variable     d_condition;
    int num_queues = 2 * 3; 
    std::deque<std::unique_ptr<queued_transmission>>  d_queue[2 * 3];
public:
    transmission_thread_queue() {

    }
    void push(std::unique_ptr<queued_transmission> value, int priorityLevel) {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            this->d_queue[priorityLevel].push_front(std::move(value));
        }
        this->d_condition.notify_one();
    }
    std::unique_ptr<queued_transmission> pop() {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=] {
            for(int i = 0; i < this->num_queues; i++) {
                if (!this->d_queue[i].empty()) return true;
            }
            return false;
        });
        for (int priorityLevel = 0; priorityLevel < num_queues; priorityLevel++) {
            if (!this->d_queue[priorityLevel].empty()) {
                std::unique_ptr<queued_transmission> rc = std::move(this->d_queue[priorityLevel].back());
                this->d_queue[priorityLevel].pop_back();
                return rc;
            }
        }
        return nullptr;
    }
};

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(0,1000); // guaranteed unbiased

transmission_thread_queue* transmission_tq;
std::vector<std::thread> transmission_threads;
std::unordered_map<std::string, int> lookupTable;


PubSub::PubSub(config_t config_, int num_threads_, std::mutex& prom_mtx_) :
    config(config_), num_threads(num_threads_), prom_mtx(prom_mtx_)
{
    const auto host_name = boost::asio::ip::host_name();

    // Setup MQTT
    this->local_mqtt = new Mqtt(host_name + "_" + to_string(uni(rng)), this->config.local_mqtt_broker, this->config.local_mqtt_port, this);
    this->remote_mqtt = NULL;
    if (this->config.remote_mqtt_port != 0) {
        if (this->config.remote_mqtt_username != "") {
            this->remote_mqtt = new Mqtt(host_name + "_" + to_string(uni(rng)), this->config.remote_mqtt_broker, this->config.remote_mqtt_port, this->config.remote_mqtt_username, this->config.remote_mqtt_password, this);
        } else {
            this->remote_mqtt = new Mqtt(host_name + "_" + to_string(uni(rng)), this->config.remote_mqtt_broker, this->config.remote_mqtt_port, this);
        }
    }

    // Setup DDS
    this->dds = new Dds(this, config_);

    // Setup Zenoh
    zenoh::ZResult *err = nullptr;
    zenoh::Config zconfig = zenoh::Config::from_file("/zenoh_config.json5", err); 
    if(!config.zenoh_endpoint.empty()) {
        zconfig.insert_json5("connect/endpoints", "[\"tcp/" + config.zenoh_endpoint + ":7447\"]", err);
    } else {
        std::cout << "No Zenoh endpoint configured, using default configuration." << std::endl;
    }

    if (err) {
        std::cout << "Error in Zenoh configuration: " << static_cast<const void*>(err) << std::endl;
    }
    
    session = new zenoh::Session(std::move(zenoh::Session::open(std::move(zconfig))));
    std::cout << "Zenoh session established" << std::endl;

    //Initialize Zenoh shared memory provider with 10 MB size and 2-byte alignment.
    static constexpr auto SHM_SIZE  = 1024U * 1024U * 10U;
    static constexpr auto SHM_ALIGN = 2U;
    zenoh::MemoryLayout layout(SHM_SIZE, zenoh::AllocAlignment({SHM_ALIGN}));
    shm_provider = new zenoh::PosixShmProvider(layout);

    transmission_tq = new transmission_thread_queue();
    for(int i = 0; i < num_threads; i++) {
        transmission_threads.push_back(std::thread(message_transmission_thread, i));
        transmission_threads[i].detach();
    }
}

std::map<std::string, PubSub_application*> subscribers;

PubSub::~PubSub() {
    // TODO: Call MQTT & DDS Destructors
}

void PubSub::on_message(std::string topic, std::string message, int priority) {
    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    std::vector<uint8_t> emptyVector;
    queued_transmission qt{topic, message, emptyVector, false, time_reception, ""};    
    transmission_tq->push(std::make_unique<queued_transmission>(std::move(qt)), lookupTable[topic] + (3 * priority));
}

void PubSub::on_message(std::string topic, const std::vector<uint8_t>& message, int priority, std::string test) {
    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    queued_transmission qt{topic, "", message, true, time_reception, test};
    transmission_tq->push(std::make_unique<queued_transmission>(std::move(qt)), lookupTable[topic] + (3 * priority));
}

void PubSub::subscribe(message_config_t message_config, PubSub_application* app) {
    std::string topic = message_config.topic_in;
    subscribers[topic] = app;
    subscribers[topic + "_enc"] = app;
    lookupTable[topic] = app->priority;
    if(message_config.dds_enabled) {
        this->dds->subscribe(topic);
        this->dds->provison_publisher(message_config.topic_out);
        this->dds->provison_publisher(message_config.topic_time);
    }
    if(message_config.mqtt_enabled) {
        this->local_mqtt->subscribe(topic);
        if(this->remote_mqtt != NULL) {
            std::string remote_topic = this->config.remote_mqtt_prefix + std::to_string(this->config.station_id) + "/" + topic;
            subscribers[remote_topic] = app;
            lookupTable[remote_topic] = app->priority;
            this->remote_mqtt->subscribe(remote_topic);
        }
    }
    if(message_config.zenoh_enabled){
        session->declare_background_subscriber(
            zenoh::KeyExpr(topic),
            [this, topic](const zenoh::Sample& sample) {
                std::string message = sample.get_payload().as_string();
                this->on_message(topic, message, 0);                         // TODO: think about priority since DDS is 0 and MQTT is 1
            },
            zenoh::closures::none
        );
        session->declare_publisher(zenoh::KeyExpr(message_config.topic_out));
        session->declare_publisher(zenoh::KeyExpr(message_config.topic_time));
    }

}

void PubSub::manual_provision(message_config_t message_config, std::string topic) {
    if(message_config.dds_enabled) {
        this->dds->provison_publisher(topic);
    }
}

void PubSub::declare_zenoh_publisher(message_config_t message_config, std::string topic) {
    if(message_config.zenoh_enabled){
        this->session->declare_publisher(zenoh::KeyExpr(topic));
    }
}

void PubSub::manual_subscribe(message_config_t message_config, std::string topic, PubSub_application* app) {
    subscribers[topic] = app;
    subscribers[topic + "_enc"] = app;
    lookupTable[topic] = app->priority;
    if(message_config.dds_enabled) this->dds->subscribe(topic);
    if(message_config.mqtt_enabled) {
        this->local_mqtt->subscribe(topic);
        if(this->remote_mqtt != NULL) this->remote_mqtt->subscribe(topic);
    }
    if(message_config.zenoh_enabled){
        session->declare_background_subscriber(
            zenoh::KeyExpr(topic),
            [this, topic](const zenoh::Sample& sample) {
                std::string message = sample.get_payload().as_string();
                this->on_message(topic, message, 0);                         // TODO: think about priority since DDS is 0 and MQTT is 1
            },
            zenoh::closures::none
        );
    }
}

void PubSub::publish_encoded(message_config_t message_config, const std::vector<uint8_t>& payload, int16_t rssi, bool newInfo, int16_t packetSize, int32_t stationID, int32_t receiverID, int16_t receiverType, double timestamp, string test){
    if(message_config.dds_enabled) {
        this->dds->publish(message_config.topic_out, payload, rssi, newInfo, packetSize, stationID, receiverID, receiverType, timestamp, test);
    }
}

void PubSub::publish(message_config_t message_config, rapidjson::Document& message_json, boost::asio::ip::udp::socket* udp_socket, boost::asio::ip::udp::endpoint* remote_endpoint, boost::system::error_code* err, prometheus::Counter* counter, prometheus::Counter* latency, double time_received, double time_encoded, double time_queue, double time_queue2, std::string message_type) {
    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    message_json.Accept(writer);
    const char* messageJSON = fullBuffer.GetString();

    if(message_config.udp_out_port != 0) {
        udp_socket->send_to(boost::asio::buffer(messageJSON, strlen(messageJSON)), *remote_endpoint, 0, *err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(message_config.dds_enabled) this->dds->publish(message_config.topic_out, messageJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(message_config.mqtt_enabled) this->local_mqtt->publish(message_config.topic_out, messageJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(message_config.mqtt_enabled && this->remote_mqtt != NULL) this->remote_mqtt->publish(this->config.remote_mqtt_prefix + std::to_string(this->config.station_id) + "/" + message_config.topic_out, messageJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    
    prom_mtx.lock();
    counter->Increment();
    latency->Increment(time_full_remote - time_received);
    prom_mtx.unlock();

    if(message_config.mqtt_test_enabled) {
        Document::AllocatorType& allocator = message_json.GetAllocator();
        message_json["test"].AddMember("start_processing_timestamp", time_queue, allocator);
        message_json["test"].AddMember("start_processing_timestamp2", time_queue2, allocator);
        if (config.publish_encoded_payloads != 0) message_json["test"].AddMember("encoded_timestamp", time_encoded, allocator);
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

void PubSub::publish_time(message_config_t message_config, rapidjson::Value& message_json) {
    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    message_json.Accept(writer);
    const char* messageJSON = fullBuffer.GetString();

    if(message_config.dds_enabled) this->dds->publish(message_config.topic_time, messageJSON);
    if(message_config.zenoh_enabled) {
        const size_t output_len = strlen(messageJSON);
        auto output_alloc_result = this->shm_provider->alloc_gc_defrag_blocking(output_len, zenoh::AllocAlignment({0}));
        zenoh::ZShmMut&& output_buf = std::get<zenoh::ZShmMut>(std::move(output_alloc_result));
        memcpy(output_buf.data(), messageJSON, output_len);
        this->session->put(message_config.topic_time, std::move(output_buf));
    }
    this->local_mqtt->publish(message_config.topic_time, messageJSON);
    if (this->remote_mqtt != NULL) this->remote_mqtt->publish(this->config.remote_mqtt_prefix + std::to_string(this->config.station_id) + "/" + message_config.topic_time, messageJSON);
}

void message_transmission_thread(int i) {
    while (true){
        std::unique_ptr<queued_transmission> qt = transmission_tq->pop();   
        subscribers[qt->topic]->on_message(qt->topic, qt->message, qt->payload, qt->is_encoded, qt->time_reception, qt->test, get_router(i));

    }
}

