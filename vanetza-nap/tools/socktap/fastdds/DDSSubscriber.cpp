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

DDSSubscriber::DDSSubscriber(DataReaderListener* listener, TypeSupport* type) : topic_(nullptr), reader_(nullptr), readerListener_(listener), type_(type) {
}

DDSSubscriber::~DDSSubscriber() {
    if (reader_ != nullptr) {
        get_subscriber(participantName_, domain_id_)->delete_datareader(reader_);
    }
    if (topic_ != nullptr) {
        get_participant(participantName_, domain_id_)->delete_topic(topic_);
    }
    if (subscriber_ != nullptr) {
        get_participant(participantName_, domain_id_)->delete_subscriber(subscriber_);
    }
    //DomainParticipantFactory::get_instance()->delete_participant(participant_);
}

//!Initialize the subscriberDDSSubscriber::
bool DDSSubscriber::init(const eprosima::fastrtps::fixed_string<255> &participantName, \
                        DomainId_t domain_id, \
                        std::basic_string<char> &topic_name, \
                        const std::basic_string<char> &type_name, \
                        const TopicQos &topic_qos
) {
    participantName_ = participantName;
    domain_id_ = domain_id_;

    // Register the Type
    type_->register_type(get_participant(participantName, domain_id), type_name);

    // Create the subscriptions Topic
    topic_ = get_participant(participantName, domain_id)->create_topic(topic_name, type_name, topic_qos);

    if (topic_ == nullptr) {
        return false;
    }    

    // Create the DataReader
    reader_ = get_subscriber(participantName, domain_id)->create_datareader(topic_, DATAREADER_QOS_DEFAULT, readerListener_);

    if (reader_ == nullptr) {
        return false;
    }

    return true;
}


