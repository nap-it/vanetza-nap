#ifndef LINK_LAYER_HPP_FGEK0QTH
#define LINK_LAYER_HPP_FGEK0QTH

#include "ethernet_device.hpp"
#include <boost/asio/io_service.hpp>
#include <cstdint>
#include <memory>
#include <string>
#include <vanetza/access/interface.hpp>
#include <vanetza/net/cohesive_packet.hpp>
#include <vanetza/net/ethernet_header.hpp>

class LinkLayerIndication {
public:
    using IndicationCallback = std::function<void(vanetza::CohesivePacket&&, const vanetza::EthernetHeader&)>;

    virtual void indicate(IndicationCallback) = 0;
    virtual ~LinkLayerIndication() = default;
};

class LinkLayer : public vanetza::access::Interface, public LinkLayerIndication {};

std::unique_ptr<LinkLayer> create_link_layer(boost::asio::io_service&, const EthernetDevice&, const std::string& name, const std::string& device_name, const bool rssi_enabled);

std::unique_ptr<LinkLayer> create_link_layer_transport(boost::asio::io_service&, const EthernetDevice&, const std::string& device_name, uint16_t port);

#endif /* LINK_LAYER_HPP_FGEK0QTH */
