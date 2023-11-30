#include "dds.hpp"
#include "pubsub.hpp"
#include <map>

using namespace boost::asio;

class SubListener : public DataReaderListener {
public:
    SubListener(Dds* dds_) : dds(dds_) {
    }

    ~SubListener() override {}

    void on_subscription_matched(DataReader*, const SubscriptionMatchedStatus& info) override {
        if (info.current_count_change == 1) {
            std::cout << "Subscriber matched." << std::endl;
        } else if (info.current_count_change == -1) {
            std::cout << "Subscriber unmatched." << std::endl;
        } else {
            std::cout << info.current_count_change
                << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
        }
    }

    void on_data_available(DataReader* reader) override {
        SampleInfo info;
        if (reader->take_next_sample(&message, &info) == ReturnCode_t::RETCODE_OK) {
            if (info.valid_data) {
                dds->on_message(reader->get_topicdescription()->get_name(), message.message());
                std::cout << "Message: " << message.message() << " RECEIVED." << std::endl;
            }
        }
    }
    MQTTMessage message;
    Dds* dds;
};

SubListener* listener_;
TypeSupport* typeSupport;
MQTTMessagePubSubType mqttMessagePubSubType;
std::map<std::string, std::unique_ptr<DDSPublisher<MQTTMessage, MQTTMessagePubSubType>>> dds_publishers;
std::map<std::string, std::unique_ptr<DDSSubscriber>> dds_subscribers;

Dds::Dds(int to_dds_key, int from_dds_key, PubSub* pubsub_) {
    this->pubsub = pubsub_;
    listener_ = new SubListener(this);
    typeSupport = new TypeSupport(&mqttMessagePubSubType);
    std::thread dds_th(&Dds::from_dds_thread, this);
    dds_th.detach();
}

Dds::~Dds() {

}

void Dds::publish(string topic, string message) {
    MQTTMessage* mqttMessage = new MQTTMessage();
    mqttMessage->uuid(1);
    mqttMessage->topic(topic);
    mqttMessage->message(message);
    mqttMessage->datetime(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    dds_publishers[topic].get()->publish(mqttMessage);
}

void Dds::subscribe(string topic) {
    std::unique_ptr<DDSSubscriber> ptr = \
        std::make_unique<DDSSubscriber>(listener_, typeSupport);
    ptr.get()->init("Vanetza", 0, topic, "MQTTMessage", TOPIC_QOS_DEFAULT);
    dds_subscribers[topic] = std::move(ptr);
}

void Dds::provison_publisher(string topic) {
    std::unique_ptr<DDSPublisher<MQTTMessage, MQTTMessagePubSubType>> ptr = \
        std::make_unique<DDSPublisher<MQTTMessage, MQTTMessagePubSubType>>(typeSupport);
    ptr.get()->init("Vanetza", 0, topic, "MQTTMessage", TOPIC_QOS_DEFAULT);
    dds_publishers[topic] = std::move(ptr);
}

void Dds::from_dds_thread() {
    while(1) {
        std::this_thread::sleep_for(std::chrono::seconds(100));
    }
}

void Dds::on_message(string topic, string message) {
    this->pubsub->on_message(topic, message, 0);
}