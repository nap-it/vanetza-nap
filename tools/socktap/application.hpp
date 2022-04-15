#ifndef APPLICATION_HPP_PSIGPUTG
#define APPLICATION_HPP_PSIGPUTG

#include <vanetza/btp/data_interface.hpp>
#include <vanetza/btp/data_indication.hpp>
#include <vanetza/btp/data_request.hpp>
#include <vanetza/btp/port_dispatcher.hpp>
#include <vanetza/geonet/data_confirm.hpp>
#include <vanetza/geonet/router.hpp>
#include "asn1json.hpp"

#include <nlohmann/json.hpp>
#include "mqtt.h"
#include "router_context.hpp"
#include "config.hpp"

#include <prometheus/counter.h>
#include <prometheus/registry.h>
class Application : public vanetza::btp::IndicationInterface
{
public:
    using DataConfirm = vanetza::geonet::DataConfirm;
    using DataIndication = vanetza::btp::DataIndication;
    using DataRequest = vanetza::btp::DataRequestGeoNetParams;
    using DownPacketPtr = vanetza::geonet::Router::DownPacketPtr;
    using PortType = vanetza::btp::port_type;
    using PromiscuousHook = vanetza::btp::PortDispatcher::PromiscuousHook;
    using UpPacketPtr = vanetza::geonet::Router::UpPacketPtr;

    Application() = default;
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    virtual ~Application() = default;

    virtual PortType port() = 0;
    virtual PromiscuousHook* promiscuous_hook();
    void on_message(string);

protected:
    DataConfirm request(const DataRequest&, DownPacketPtr);

private:
    friend class RouterContext;
    vanetza::geonet::GbcDataRequest request_gbc(const DataRequest&);
    vanetza::geonet::ShbDataRequest request_shb(const DataRequest&);
    vanetza::geonet::Router* router_;
};

#endif /* APPLICATION_HPP_PSIGPUTG */

