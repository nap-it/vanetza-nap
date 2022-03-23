#include "complete_packet.hpp"

CompletePacket::CompletePacket(const vanetza::ByteBuffer& buffer, vanetza::OsiLayer layer, vanetza::EthernetHeader& ethHeader, int rssi, double time_reception) :
    CohesivePacket(buffer, layer), ethHeader(ethHeader), rssi(rssi), time_reception(time_reception)
{}

CompletePacket::CompletePacket(vanetza::ByteBuffer&& buffer, vanetza::OsiLayer layer, vanetza::EthernetHeader& ethHeader, int rssi, double time_reception) :
    CohesivePacket(buffer, layer), ethHeader(ethHeader), rssi(rssi), time_reception(time_reception)
{}