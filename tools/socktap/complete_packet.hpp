#include <vanetza/net/cohesive_packet.hpp>
#include <vanetza/net/ethernet_header.hpp>

class CompletePacket : public vanetza::CohesivePacket
{
public:
    CompletePacket(const vanetza::ByteBuffer& buffer, vanetza::OsiLayer layer, vanetza::EthernetHeader& ethHeader, int rssi, double time_reception);
    CompletePacket(vanetza::ByteBuffer&& buffer, vanetza::OsiLayer layer, vanetza::EthernetHeader& ethHeader, int rssi, double time_reception);

    vanetza::EthernetHeader& ethHeader;
    int rssi;
    double time_reception;
};

