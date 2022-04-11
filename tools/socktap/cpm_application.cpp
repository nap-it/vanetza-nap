#include "cpm_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

// This is a very simple CA application sending CAMs at a fixed rate.

using namespace vanetza;
using namespace vanetza::facilities;
using namespace std::chrono;
using json = nlohmann::json;

CpmApplication::CpmApplication(PositionProvider& positioning, Runtime& rt, Mqtt *mqtt_) :
    positioning_(positioning), runtime_(rt), cpm_interval_(seconds(1))
{
    mqtt = mqtt_;
    //persistence = {};
    //schedule_timer();
    mqtt->subscribe("target/cpm", this);
}

void CpmApplication::set_interval(Clock::duration interval)
{
    cpm_interval_ = interval;
    runtime_.cancel(this);
    //schedule_timer();
}

void CpmApplication::print_generated_message(bool flag)
{
    print_tx_msg_ = flag;
}

void CpmApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

CpmApplication::PortType CpmApplication::port()
{
    return btp::ports::CPM;
}

void CpmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    asn1::PacketVisitor<asn1::Cpm> visitor;
    std::shared_ptr<const asn1::Cpm> cpm = boost::apply_visitor(visitor, *packet);

    std::cout << "CPM application received a packet with " << (cpm ? "decodable" : "broken") << " content" << std::endl;
    mqtt->publish("vanetza/cpm", buildJSON(*cpm));

    //CollectivePerceptionMessage_t cpm_j = json::parse("{\"generationDeltaTime\":100,\"cpmParameters\":{\"managementContainer\":{\"stationType\":15,\"referencePosition\":{\"latitude\":40.64088,\"longitude\":-8.65397,\"positionConfidenceEllipse\":{\"semiMajorConfidence\":4095,\"semiMinorConfidence\":4095,\"semiMajorOrientation\":0},\"altitude\":{\"altitudeValue\":2.9,\"altitudeConfidence\":14}}},\"stationDataContainer\":{\"originatingVehicleContainer\":{\"heading\":{\"headingValue\":3601,\"headingConfidence\":127},\"speed\":{\"speedValue\":16383,\"speedConfidence\":127},\"driveDirection\":0}},\"sensorInformationContainer\":[{\"sensorID\":1,\"type\":1,\"detectionArea\":{\"stationarySensorRectangle\":{\"semiMajorRangeLength\":750,\"semiMinorRangeLength\":20,\"semiMajorRangeOrientation\":3601}}},{\"sensorID\":2,\"type\":12,\"detectionArea\":{\"stationarySensorRadial\":{\"range\":100,\"stationaryHorizontalOpeningAngleStart\":3601,\"stationaryHorizontalOpeningAngleEnd\":3601}}}],\"perceivedObjectContainer\":[{\"objectID\":1033,\"timeOfMeasurement\":1648737497.699,\"objectConfidence\":0,\"xDistance\":{\"value\":0,\"confidence\":0},\"yDistance\":{\"value\":0,\"confidence\":0},\"xSpeed\":{\"value\":11.3,\"confidence\":0},\"ySpeed\":{\"value\":11.3,\"confidence\":0},\"xAcceleration\":{\"longitudinalAccelerationValue\":1,\"longitudinalAccelerationConfidence\":1},\"yAcceleration\":{\"lateralAccelerationValue\":1,\"lateralAccelerationConfidence\":1},\"objectRefPoint\":0,\"classification\":[{\"confidence\":0,\"class\":{\"vehicle\":{\"type\": 1, \"confidence\": 2}}}]},{\"objectID\":1,\"timeOfMeasurement\":1648565786.0646236,\"objectConfidence\":0,\"xDistance\":{\"value\":0,\"confidence\":0},\"yDistance\":{\"value\":0,\"confidence\":0},\"xSpeed\":{\"value\":0,\"confidence\":0},\"ySpeed\":{\"value\":0,\"confidence\":0},\"xAcceleration\":{\"longitudinalAccelerationValue\":2,\"longitudinalAccelerationConfidence\":2},\"yAcceleration\":{\"lateralAccelerationValue\":1,\"lateralAccelerationConfidence\":2},\"objectRefPoint\":0,\"classification\":[{\"confidence\":0,\"class\":{\"person\":{\"type\": 1, \"confidence\": 2}}}]},{\"objectID\":1,\"timeOfMeasurement\":1648565786.0646236,\"objectConfidence\":0,\"xDistance\":{\"value\":0,\"confidence\":0},\"yDistance\":{\"value\":0,\"confidence\":0},\"xSpeed\":{\"value\":0,\"confidence\":0},\"ySpeed\":{\"value\":0,\"confidence\":0},\"xAcceleration\":{\"longitudinalAccelerationValue\":3,\"longitudinalAccelerationConfidence\":3},\"yAcceleration\":{\"lateralAccelerationValue\":3,\"lateralAccelerationConfidence\":3},\"objectRefPoint\":0,\"classification\":[{\"confidence\":0,\"class\":{\"person\":{\"type\": 1, \"confidence\": 2}}}]}],\"numberOfPerceivedObjects\":3}}");
    //std::cout << "Finished Generating CPM object " << std::endl;
    //json j2 = cpm_j;
    //std::cout << "CPM JSON: " << j2 << std::endl;
    
}

void CpmApplication::schedule_timer()
{
    runtime_.schedule(cpm_interval_, std::bind(&CpmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CpmApplication::buildJSON(vanetza::asn1::Cpm message) {
    // ItsPduHeader_t& header = message->header;
    // CollectivePerceptionMessage_t & cpm = message->cpm;
    // CpmManagementContainer_t & mgc = cpm.cpmParameters.managementContainer;
    // ReferencePosition_t & rfp = mgc.referencePosition;
    // // //json j = denm;
    // // //std::cout << "DENM JSON: " << j << std::endl;

    // nlohmann::json json_payload = {
    //         {"timestamp", time_reception},
    //         {"newInfo", true},
    //         {"rssi", -255},
    //         {"test", {
    //             {"json_timestamp", (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0}
    //         }
    //         },
    //         {"stationID", (long) header.stationID},
    //         {"stationType", (long) mgc.stationType},
    //         {"latitude", (long) rfp.latitude},
    //         {"longitude", (long) rfp.longitude},
    // };
    // return json_payload.dump();
    CollectivePerceptionMessage_t& cpm = message->cpm;
    json j = cpm;
    std::cout << "CPM JSON: " << j << std::endl;

    return j.dump();
}

void CpmApplication::on_message(string mqtt_message) {
    json payload = json::parse(mqtt_message);
    cout << "parsed" << endl;
    CollectivePerceptionMessage_t cpm = payload.get<CollectivePerceptionMessage_t>();
    cout << "parsed2" << endl;

    vanetza::asn1::Cpm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cpm;
    header.stationID = 1; // some dummy value

    message->cpm = cpm;

    json j = message->cpm;
    std::cout << "a0 " << j << std::endl;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    std::cout << "a1 " << std::endl;

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    std::cout << "a2 " << std::endl;

    auto confirm = Application::request(request, std::move(packet));
    std::cout << "a3 " << std::endl;
    if (!confirm.accepted()) {
        throw std::runtime_error("CPM application data request failed");
    }

    std::cout << "a4 " << std::endl;
}

void CpmApplication::send(vanetza::asn1::Cpm message) {
    
}

void CpmApplication::on_timer(Clock::time_point)
{
    //schedule_timer();
    vanetza::asn1::Cpm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cpm;
    header.stationID = 99;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();
    message->cpm.generationDeltaTime = gen_delta_time * GenerationDeltaTime_oneMilliSec;

    auto position = positioning_.position_fix();

    CpmManagementContainer_t& management = message->cpm.cpmParameters.managementContainer;
    management.stationType = StationType_passengerCar;
    copy(position, management.referencePosition);

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::DEN;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    auto confirm = Application::request(request, std::move(packet));
    if (!confirm.accepted()) {
        throw std::runtime_error("CPM application data request failed");
    }

}
