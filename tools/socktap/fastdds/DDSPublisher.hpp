#ifndef DDSPUBLISHER_H
#define DDSPUBLISHER_H

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include "DDSCommon.hpp"

using namespace eprosima::fastdds::dds;

class PubListener : public DataWriterListener {
public:
    PubListener() : matched_(0) {
    }

    ~PubListener() override {}

    void on_publication_matched(DataWriter*, const PublicationMatchedStatus& info) override {
        if (info.current_count_change == 1) {
            matched_ = info.total_count;
            std::cout << "New DDS Subscriber Discovered" << std::endl;
        }
        else if (info.current_count_change == -1) {
            matched_ = info.total_count;
            std::cout << "Existing DDS Subscriber Removed" << std::endl;
        }
        else {
            std::cout << info.current_count_change
                << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
        }
    }
    std::atomic_int matched_;
};

template <class MSG, class MSG_TYPE>
class DDSPublisher {
public:
    DDSPublisher(TypeSupport* type) : topic_(nullptr), writer_(nullptr), type_(type) {}
    ~DDSPublisher() {
        if (writer_ != nullptr)
        {
            get_publisher(participantName_, domain_id_)->delete_datawriter(writer_);
        }
        if (publisher_ != nullptr)
        {
            get_participant(participantName_, domain_id_)->delete_publisher(publisher_);
        }
        if (topic_ != nullptr)
        {
            get_participant(participantName_, domain_id_)->delete_topic(topic_);
        }
        //DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    /**
     *
     * @param participantName
     * @param domain_id
     * @param topic_name
     * @param type_name
     * @param topic_qos
     * @return
     */
    bool init(const eprosima::fastrtps::fixed_string<255> &participantName, \
            DomainId_t domain_id, \
            std::basic_string<char> &topic_name, \
            const std::basic_string<char> &type_name, \
            const TopicQos &topic_qos) {
        participantName_ = participantName;
        domain_id_ = domain_id_;

        // Register the Type
        type_->register_type(get_participant(participantName, domain_id), type_name);

        // Create the publications Topic
        topic_ = get_participant(participantName, domain_id)->create_topic(topic_name, type_name, topic_qos);

        if (topic_ == nullptr)
        {
            std::cout << "[Topic] Not created" << std::endl;
            return false;
        }

        // Create the DataWriter
        writer_ = get_publisher(participantName, domain_id)->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT, &writerListener_);

        if (writer_ == nullptr)
        {
            std::cout << "[DataWriter] Not created" << std::endl;
            return false;
        }
        return true;
    }

    bool publish(std::unique_ptr<MSG> msg) {
        //std::cout << "Going to publish" << std::endl;
        if (writerListener_.matched_ > 0)
        {
            writer_->write(msg.get());
            //std::cout << "Published" << std::endl;
            return true;
        }
        return false;
    }
    //void run();

private:
    PubListener writerListener_;
    Topic* topic_;
    DataWriter* writer_;
    TypeSupport* type_;
    eprosima::fastrtps::fixed_string<255> participantName_;
    DomainId_t domain_id_;
};
#endif //DDSPUBLISHER_H
