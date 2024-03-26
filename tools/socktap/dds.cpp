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
            std::cout << "New DDS Publisher Discovered" << std::endl;
        } else if (info.current_count_change == -1) {
            std::cout << "Existing DDS Publisher Removed" << std::endl;
        } else {
            std::cout << info.current_count_change
                << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
        }
    }

    void on_data_available(DataReader* reader) override {
        SampleInfo info;
        if(reader->get_topicdescription()->get_type_name() == "MQTTMessage") {
            MQTTMessage message;
            if (reader->take_next_sample(&message, &info) == ReturnCode_t::RETCODE_OK) {
                if (info.valid_data) {
                    dds->on_message(reader->get_topicdescription()->get_name(), message.message());
                    //std::cout << "Message: " << message.message() << " RECEIVED ON TOPIC " << reader->get_topicdescription()->get_name() << std::endl;
                }
            }
        } else {
            EncodedITSMessage encodedMessage;
            if (reader->take_next_sample(&encodedMessage, &info) == ReturnCode_t::RETCODE_OK) {
                if (info.valid_data) {
                    dds->on_message(reader->get_topicdescription()->get_name(), encodedMessage.message(), (encodedMessage.test().has_value() ? encodedMessage.test().value() : std::string("")));
                }
            }
        }
    }

    Dds* dds;
};

SubListener* listener_;
TypeSupport* typeSupport;
TypeSupport* encodedTypeSupport;
MQTTMessagePubSubType mqttMessagePubSubType;
EncodedITSMessagePubSubType encodedITSMessagePubSubType;
std::map<std::string, std::unique_ptr<DDSPublisher<MQTTMessage, MQTTMessagePubSubType>>> json_dds_publishers;
std::map<std::string, std::unique_ptr<DDSPublisher<EncodedITSMessage, EncodedITSMessagePubSubType>>> encoded_dds_publishers;
std::map<std::string, std::unique_ptr<DDSSubscriber>> dds_subscribers;

Dds::Dds(PubSub* pubsub_, config_t config) {
    this->pubsub = pubsub_;
    listener_ = new SubListener(this);
    typeSupport = new TypeSupport(&mqttMessagePubSubType);
    encodedTypeSupport = new TypeSupport(&encodedITSMessagePubSubType);
    std::thread dds_th(&Dds::from_dds_thread, this);
    dds_th.detach();
    this->participantName = config.dds_participant_name;
    if (config.dds_domain_id >= 0 && config.dds_domain_id <= 232) {
        this->domain_id = config.dds_domain_id;
    } else {
        std::cout << "DDS Domain ID is outside allowed range (0-232). Using default ID (0)" << std::endl;
        this->domain_id = 0;
    }
    
}

Dds::~Dds() {

}

void Dds::publish(string topic, string message) {
    std::unique_ptr<MQTTMessage> mqttMessage = std::make_unique<MQTTMessage>();
    mqttMessage->uuid(1);
    mqttMessage->topic(topic);
    mqttMessage->message(message);
    mqttMessage->datetime(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    json_dds_publishers[topic]->publish(std::move(mqttMessage));
}

void Dds::publish(string topic, const std::vector<uint8_t>& payload, int16_t rssi, bool newInfo, int16_t packetSize, int32_t stationID, int32_t receiverID, int16_t receiverType, double timestamp, string test) {
    std::unique_ptr<EncodedITSMessage> encodedITSMessage = std::make_unique<EncodedITSMessage>();
    encodedITSMessage->topic(topic + "_enc");
    encodedITSMessage->message(payload);
    encodedITSMessage->rssi(eprosima::fastcdr::optional<int16_t>(rssi));
    encodedITSMessage->newInfo(eprosima::fastcdr::optional<bool>(newInfo));
    encodedITSMessage->packetSize(eprosima::fastcdr::optional<int16_t>(packetSize));
    encodedITSMessage->stationID(eprosima::fastcdr::optional<int32_t>(stationID));
    encodedITSMessage->receiverID(eprosima::fastcdr::optional<int32_t>(receiverID));
    encodedITSMessage->receiverType(eprosima::fastcdr::optional<int16_t>(receiverType));
    encodedITSMessage->timestamp(eprosima::fastcdr::optional<double>(timestamp));
    encodedITSMessage->test(eprosima::fastcdr::optional<string>(test));
    encoded_dds_publishers[topic]->publish(std::move(encodedITSMessage));
}

void Dds::subscribe(string topic) {
    std::unique_ptr<DDSSubscriber> ptr = \
        std::make_unique<DDSSubscriber>(listener_, typeSupport);
    ptr.get()->init(participantName, domain_id, topic, "MQTTMessage", TOPIC_QOS_DEFAULT);
    std::unique_ptr<DDSSubscriber> ptr_enc = \
        std::make_unique<DDSSubscriber>(listener_, encodedTypeSupport);
    std::string enc_topic = topic + "_enc";
    ptr_enc.get()->init(participantName, domain_id, enc_topic, "EncodedITSMessage", TOPIC_QOS_DEFAULT);
    dds_subscribers[topic] = std::move(ptr);
    dds_subscribers[topic + "_enc"] = std::move(ptr_enc);
}

void Dds::provison_publisher(string topic) {
    std::unique_ptr<DDSPublisher<MQTTMessage, MQTTMessagePubSubType>> ptr = \
        std::make_unique<DDSPublisher<MQTTMessage, MQTTMessagePubSubType>>(typeSupport);
    ptr.get()->init(participantName, domain_id, topic, "MQTTMessage", TOPIC_QOS_DEFAULT);
    std::unique_ptr<DDSPublisher<EncodedITSMessage, EncodedITSMessagePubSubType>> ptr_enc = \
        std::make_unique<DDSPublisher<EncodedITSMessage, EncodedITSMessagePubSubType>>(encodedTypeSupport);
    std::string enc_topic = topic + "_enc";
    ptr_enc.get()->init(participantName, domain_id, enc_topic, "EncodedITSMessage", TOPIC_QOS_DEFAULT);
    json_dds_publishers[topic] = std::move(ptr);
    encoded_dds_publishers[topic] = std::move(ptr_enc);
}

void Dds::from_dds_thread() {
    while(1) {
        std::this_thread::sleep_for(std::chrono::seconds(100));
    }
}

void Dds::on_message(string topic, string message) {
    this->pubsub->on_message(topic, message, 0);
}

void Dds::on_message(string topic, const std::vector<uint8_t>& payload, string test) {
    this->pubsub->on_message(topic, payload, 0, test);
}
