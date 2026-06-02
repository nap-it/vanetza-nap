#include "pmm_application.hpp"
#include <rapidjson/document.h>
#include <vanetza/asn1/rj/jer_rj_encode.hpp>
#include <vanetza/asn1/rj/jer_rj_decode.hpp>
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/pmm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

using namespace vanetza;
using namespace std::chrono;
using namespace boost::asio;

prometheus::Counter *pmm_rx_counter;
prometheus::Counter *pmm_tx_counter;
prometheus::Counter *pmm_rx_latency;
prometheus::Counter *pmm_tx_latency;

boost::asio::io_service pmm_io_service_;
ip::udp::socket pmm_udp_socket(pmm_io_service_);
ip::udp::endpoint pmm_remote_endpoint;
boost::system::error_code pmm_err;

PmmApplication::PmmApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_, std::mutex& prom_mtx_) :
    PubSub_application(priority_),
    positioning_(positioning), runtime_(rt), pmm_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), priority(priority_), prom_mtx(prom_mtx_)
{
    pmm_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "pmm"}, {"direction", "rx"}}));
    pmm_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "pmm"}, {"direction", "tx"}}));
    pmm_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "pmm"}, {"direction", "rx"}}));
    pmm_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "pmm"}, {"direction", "tx"}}));

    this->pubsub->subscribe(config_s.pmm, this);

    if(config_s.pmm.udp_out_port != 0) {
        pmm_udp_socket.open(ip::udp::v4());
        pmm_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.pmm.udp_out_addr), config_s.pmm.udp_out_port);
    }
}

void PmmApplication::set_interval(Clock::duration interval)
{
    pmm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

PmmApplication::PortType PmmApplication::port()
{
    return btp::ports::PMM;
}

void PmmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    const double time_queue2 = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::r2::Pmm> visitor;
    std::shared_ptr<const asn1::r2::Pmm> pmm = boost::apply_visitor(visitor, *packet);
    if (pmm == 0) {
        std::cout << "-- Vanetza Decoding Error --\nReceived an encoded PMM message that does not meet ETSI spec" << std::endl;
        //std::cout << "\nInvalid sender: " << cp. << std::endl;
        return;
    }

    if(config_s.publish_encoded_payloads) {
        const std::vector<uint8_t> vec = std::vector<uint8_t>(cp[OsiLayer::Application].begin(), cp[OsiLayer::Application].end());
        double time_pre_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        string test = "{\"encoded_timestamp\": " + to_string(time_pre_encoded) + ", \"stationAddr\": " + cp.source + "}";
        pubsub->publish_encoded(
            config_s.pmm,
            vec, 
            cp.rssi,
            true,
            cp.size(),
            (*pmm)->header.stationId,
            config_s.station_id,
            config_s.station_type,
            cp.time_received,
            test);
    }

    rapidjson::Document pmm_doc;
    pmm_doc  = vanetza::asn1::rj::jer_encode_rj_doc(&asn_DEF_Vanetza_ITS2_PMM, pmm->content());

    rapidjson::Document output_doc;
    auto& alloc = output_doc.GetAllocator();
    output_doc.SetObject();

    output_doc.AddMember("fields", pmm_doc, alloc);

    // Add "test" field for publish function (required by pubsub when mqtt_test_enabled)
    Value jsonTest(kObjectType);
    jsonTest.AddMember("start_processing_timestamp", cp.time_queue, alloc);
    if(parse_channel_info(cp).frequency != -1) {
        jsonTest.AddMember("channel_frequency", parse_channel_info(cp).frequency, alloc);
        if (parse_channel_info(cp).noise != -1) jsonTest.AddMember("channel_noise", parse_channel_info(cp).noise, alloc);
        jsonTest.AddMember("channel_busy_time", parse_channel_info(cp).chan_busy_time, alloc);
        jsonTest.AddMember("channel_rx_time", parse_channel_info(cp).chan_rx_time, alloc);
        jsonTest.AddMember("channel_tx_time", parse_channel_info(cp).chan_tx_time, alloc);
    }
    const double time_json = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    jsonTest.AddMember("json_timestamp", time_json, alloc);
    if(config_s.mcs_enabled) {
        Value mcsValue(rapidjson::kObjectType);
        for (const auto& entry : cp.mcs) {
            Value key(entry.first.c_str(), alloc);
            Value value(entry.second);
            mcsValue.AddMember(key, value, alloc);
        }
        jsonTest.AddMember("mcs", mcsValue, alloc);
    }
    output_doc.AddMember("test", jsonTest, alloc);

    // Add metadata fields
    output_doc.AddMember("timestamp", cp.time_received, alloc);
    output_doc.AddMember("rssi", cp.rssi, alloc);
    output_doc.AddMember("stationID", Value(static_cast<int64_t>((*pmm)->header.stationId)), alloc);
    output_doc.AddMember("stationAddr", Value().SetString(cp.source.c_str(), cp.source.size(), alloc), alloc);
    output_doc.AddMember("receiverID", config_s.station_id, alloc);
    output_doc.AddMember("receiverType", config_s.station_type, alloc);
    output_doc.AddMember("packet_size", static_cast<int>(cp.size()), alloc);

    const double time_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    pubsub->publish(config_s.pmm, output_doc, &pmm_udp_socket, &pmm_remote_endpoint, &pmm_err, pmm_rx_counter, pmm_rx_latency, cp.time_received, time_encoded, cp.time_queue, time_queue2, "pmm");
}

void PmmApplication::schedule_timer()
{
    runtime_.schedule(pmm_interval_, std::bind(&PmmApplication::on_timer, this, std::placeholders::_1), this);
}

void PmmApplication::on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router) {

    const double time_processing = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    DownPacketPtr packet { new DownPacket() };
    Document document;

    int payload_station_id = -1;

    if (!is_encoded) {
        vanetza::asn1::r2::Pmm pmm;
        fillPosition(mqtt_message, positioning_);

        try {
            document.Parse(mqtt_message.c_str());
            if(document.HasParseError() || !document.IsObject()) {
                std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows JSON spec\n" << std::endl;
                std::cout << "Invalid payload: " << mqtt_message << std::endl;
                return;
            }
        } catch(...) {
            std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
            std::cout << "Invalid payload: " << mqtt_message << std::endl;
            return;
        }

        payload_station_id = document.HasMember("stationId") ? document["stationId"].GetInt() : -1;

        // Check if this is a full PMM (with header and payload) or just the pmm payload
        bool has_full_structure = document.HasMember("header") && document.HasMember("pmm");

        if (!has_full_structure) {
            // Wrap the payload with header and payload structure
            Document wrapper;
            auto& allocator = wrapper.GetAllocator();
            wrapper.SetObject();

			Value header(kObjectType);
			header.AddMember("protocolVersion", 3, allocator)
				.AddMember("messageId", Vanetza_ITS2_MessageId_pcim, allocator)
				.AddMember("stationId", payload_station_id != -1 ? payload_station_id : config_s.station_id, allocator);
			wrapper.AddMember("header", header, allocator);

            // Move the document content under "pmm"
            Value pmmContent;
            pmmContent.CopyFrom(document, allocator);
            wrapper.AddMember("pmm", pmmContent, allocator);

            document.Swap(wrapper);
        }

        try {
            std::string verbose_error;
            bool success = vanetza::asn1::rj::jer_decode_rj_inplace(
                &asn_DEF_Vanetza_ITS2_PMM,
                pmm.content(),
                document,
                config_s.debug_enabled ? &verbose_error : nullptr);
            if (!success) {
                std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows ETSI spec\n" << std::endl;
                if (config_s.debug_enabled && !verbose_error.empty()) {
                    std::cout << verbose_error << std::endl;
                }
                std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
                return;
            }
        } catch (VanetzaJSONException& e) {
            std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
            return;
        } catch(...) {
            std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
            std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
            return;
        }

        packet->layer(OsiLayer::Application) = std::move(pmm);
    } else {
        std::vector<unsigned char> bytesCopy(bytes.begin(), bytes.end());
        packet->layer(OsiLayer::Application) = std::move(bytesCopy);
    }

    DataRequest request;
    request.its_aid = aid::VRU;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;
    if (payload_station_id != -1) {
        apply_station_overrides(request, router, config_s.station_type, payload_station_id);
    }

    try {
        if (!Application::request(request, std::move(packet), nullptr, router)) {
            return;
        }
    } catch(std::runtime_error& e) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    if(config_s.pmm.mqtt_time_enabled) {
        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);
        Value timeTest(kObjectType);

        int station_id_time = resolve_station_id(payload_station_id, config_s.station_id);
        std::string mac_addr = resolve_station_mac(config_s.station_type, payload_station_id, config_s.mac_address);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", station_id_time, allocator)
            .AddMember("stationAddr", mac_addr, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator);
        if(!is_encoded) timePayload.AddMember("fields", document, allocator);

        timeTest.AddMember("wave_timestamp", time_now, allocator);
        timeTest.AddMember("start_processing_timestamp", time_processing, allocator);
        if(test != "") timeTest.AddMember("request_info", Value().SetString(test.c_str(), test.size()), allocator);
        timePayload.AddMember("test", timeTest, allocator);

        pubsub->publish_time(config_s.pmm, timePayload);
    }

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    prom_mtx.lock();
    pmm_tx_counter->Increment();
    pmm_tx_latency->Increment(time_now - time_reception);
    prom_mtx.unlock();
}

void PmmApplication::on_timer(Clock::time_point)
{

}
