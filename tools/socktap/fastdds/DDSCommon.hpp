#ifndef DDSCOMMON_H
#define DDSCOMMON_H

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
// #include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
// #include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.h>

using namespace eprosima::fastdds::dds;

inline DomainParticipant* participant_;
inline Publisher* publisher_;
inline Subscriber *subscriber_;

inline DomainParticipant* get_participant(const eprosima::fastrtps::fixed_string<255> &participantName, \
            DomainId_t domain_id) {
    if (participant_ == nullptr) {
        DomainParticipantQos participantQos;
        participantQos.name(participantName);
        // auto udp_transport = std::make_shared<eprosima::fastdds::rtps::UDPv4TransportDescriptor>();
        // udp_transport->interface_blocklist.emplace_back("wlan0");
        // participantQos.transport().user_transports.push_back(udp_transport);
        // auto shm_transport = std::make_shared<eprosima::fastdds::rtps::SharedMemTransportDescriptor>();
        // shm_transport->interface_blocklist.emplace_back("wlan0");
        // participantQos.transport().user_transports.push_back(shm_transport);
        // participantQos.transport().use_builtin_transports = true;
        // participant_ = DomainParticipantFactory::get_instance()->create_participant(domain_id, participantQos);

        
        std::string xml_profile =
        "\
        <?xml version=\"1.0\" encoding=\"UTF-8\" ?>\
            <profiles xmlns=\"http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles\">\
                <transport_descriptors>\
                    <transport_descriptor>\
                        <transport_id>CustomUdpTransportBlocklist</transport_id>\
                        <type>UDPv4</type>\
                        <interfaces>\
                            <blocklist>\
                                <interface name=\"wlan0\"/>\
                            </blocklist>\
                        </interfaces>\
                    </transport_descriptor>\
                    <transport_descriptor>\
                        <transport_id>CustomSHMTransportBlocklist</transport_id>\
                        <type>SHM</type>\
                        <interfaces>\
                            <blocklist>\
                                <interface name=\"wlan0\"/>\
                            </blocklist>\
                        </interfaces>\
                    </transport_descriptor>\
                </transport_descriptors>\
                <participant profile_name=\"CustomTcpTransportBlocklistParticipant\">\
                    <rtps>\
                        <name>Vanetza</name>\
                        <userTransports>\
                            <transport_id>CustomUdpTransportBlocklist</transport_id>\
                            <transport_id>CustomSHMTransportBlocklist</transport_id>\
                        </userTransports>\
                        <useBuiltinTransports>false</useBuiltinTransports>\
                    </rtps>\
                </participant>\
            </profiles>\
        ";
        DomainParticipantFactory::get_instance()->load_XML_profiles_string(xml_profile.c_str(),xml_profile.length());
        participant_ = DomainParticipantFactory::get_instance()->create_participant_with_profile(domain_id, "CustomTcpTransportBlocklistParticipant");

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