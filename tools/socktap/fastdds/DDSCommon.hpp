#ifndef DDSCOMMON_H
#define DDSCOMMON_H

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
#include <sstream>
#include <string>

using namespace eprosima::fastdds::dds;

inline DomainParticipant* participant_;
inline Publisher* publisher_;
inline Subscriber *subscriber_;

inline DomainParticipant* get_participant(const eprosima::fastrtps::fixed_string<255> &participantName,
            DomainId_t domain_id, const std::string &blocked_interfaces = "") {
    if (participant_ == nullptr) {
        DomainParticipantQos participantQos;
        participantQos.name(participantName);

        // If a comma-separated blocklist is provided, restrict DDS/RTPS traffic
        // to exclude those interfaces (e.g. the ITS-G5 wireless interface).
        if (!blocked_interfaces.empty()) {
            auto udp_transport = std::make_shared<eprosima::fastdds::rtps::UDPv4TransportDescriptor>();

            std::istringstream ss(blocked_interfaces);
            std::string iface;
            while (std::getline(ss, iface, ',')) {
                iface.erase(0, iface.find_first_not_of(" \t"));
                iface.erase(iface.find_last_not_of(" \t") + 1);
                if (!iface.empty()) {
                    udp_transport->interface_blocklist.emplace_back(iface);
                }
            }

            participantQos.transport().user_transports.push_back(udp_transport);
            participantQos.transport().use_builtin_transports = false;
        }

        participant_ = DomainParticipantFactory::get_instance()->create_participant(domain_id, participantQos);

        if (participant_ == nullptr) {
            std::cout << "[Participant] Not created" << std::endl;
        }
    }
    return participant_;
}

inline Publisher* get_publisher(const eprosima::fastrtps::fixed_string<255> &participantName, \
            DomainId_t domain_id) {
    if (publisher_ == nullptr) {
        publisher_ = get_participant(participantName, domain_id)->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);

        if (publisher_ == nullptr) {
            std::cout << "[Publisher] Not created" << std::endl;
        }
    }
    return publisher_;
}

inline Subscriber* get_subscriber(const eprosima::fastrtps::fixed_string<255> &participantName, \
            DomainId_t domain_id) {
    if (subscriber_ == nullptr) {
        subscriber_ = get_participant(participantName, domain_id)->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);

        if (subscriber_ == nullptr) {
            std::cout << "[Subscriber] Not created" << std::endl;
        }
    }
    return subscriber_;
}

#endif //DDSCOMMON_H