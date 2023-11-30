#include "DDSSubscriber.hpp"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

using namespace eprosima::fastdds::dds;

DDSSubscriber::DDSSubscriber(DataReaderListener* listener, TypeSupport* type) : participant_(nullptr), subscriber_(nullptr), topic_(nullptr), reader_(nullptr), readerListener_(listener), type_(type) {
}

DDSSubscriber::~DDSSubscriber() {
    if (reader_ != nullptr) {
        subscriber_->delete_datareader(reader_);
    }
    if (topic_ != nullptr) {
        participant_->delete_topic(topic_);
    }
    if (subscriber_ != nullptr) {
        participant_->delete_subscriber(subscriber_);
    }
    DomainParticipantFactory::get_instance()->delete_participant(participant_);
}

//!Initialize the subscriberDDSSubscriber::
bool DDSSubscriber::init(const eprosima::fastrtps::fixed_string<255> &participantName, \
                        DomainId_t domain_id, \
                        std::basic_string<char> &topic_name, \
                        const std::basic_string<char> &type_name, \
                        const TopicQos &topic_qos
) {
    DomainParticipantQos participantQos;
    participantQos.name(participantName);
    participant_ = DomainParticipantFactory::get_instance()->create_participant(domain_id, participantQos);

    if (participant_ == nullptr) {
        return false;
    }

    // Register the Type
    type_->register_type(participant_, type_name);

    // Create the subscriptions Topic
    topic_ = participant_->create_topic(topic_name, type_name, topic_qos);

    if (topic_ == nullptr) {
        return false;
    }

    // Create the Subscriber
    subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

    if (subscriber_ == nullptr) {
        return false;
    }

    // Create the DataReader
    reader_ = subscriber_->create_datareader(topic_, DATAREADER_QOS_DEFAULT, readerListener_);

    if (reader_ == nullptr) {
        return false;
    }

    return true;
}


