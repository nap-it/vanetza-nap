#ifndef DDSSUBSCRIBER_H
#define DDSSUBSCRIBER_H

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include "DDSCommon.hpp"

using namespace eprosima::fastdds::dds;

class DDSSubscriber {
public:
    DDSSubscriber(DataReaderListener* listener, TypeSupport* type);
    virtual ~DDSSubscriber();
    bool init(const eprosima::fastrtps::fixed_string<255> &participantName, \
              DomainId_t domain_id, \
              std::basic_string<char> &topic_name, \
              const std::basic_string<char> &type_name, \
              const TopicQos &topic_qos);

private:
    Subscriber *subscriber_;
    DataReader *reader_;
    Topic *topic_;
    TypeSupport* type_;
    DataReaderListener* readerListener_;
    eprosima::fastrtps::fixed_string<255> participantName_;
    DomainId_t domain_id_;
};
#endif //DDSSUBSCRIBER_H
