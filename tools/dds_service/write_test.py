from time import sleep
import rticonnextdds_connector as rti

with rti.open_connector(
        config_name="participant_library::its_app",
        url="./Vanetza_DDS_Spec.xml") as connector:

    output = connector.get_output("its_publisher::vanetza/in/cam_full")

    print("Waiting for subscriptions...")
    output.wait_for_subscriptions()

    print("Writing...")
    for i in range(1, 10):
        output.instance.set_string("message", "{\"generationDeltaTime\":100,\"camParameters\":{\"basicContainer\":{\"stationType\":18,\"referencePosition\":{\"latitude\":40.6345846,\"longitude\":-8.6594692,\"positionConfidenceEllipse\":{\"semiMajorConfidence\":4095,\"semiMinorConfidence\":4095,\"semiMajorOrientation\":147.3},\"altitude\":{\"altitudeValue\":2.0,\"altitudeConfidence\":11}}},\"highFrequencyContainer\":{\"basicVehicleContainerHighFrequency\":{\"heading\":{\"headingValue\":147.3,\"headingConfidence\":127},\"speed\":{\"speedValue\":0.0,\"speedConfidence\":127},\"driveDirection\":\"FORWARD\",\"vehicleLength\":{\"vehicleLengthValue\":10,\"vehicleLengthConfidenceIndication\":\"trailerPresenceIsUnknown\"},\"vehicleWidth\":3,\"longitudinalAcceleration\":{\"longitudinalAccelerationValue\":0,\"longitudinalAccelerationConfidence\":102},\"curvature\":{\"curvatureValue\":1023,\"curvatureConfidence\":\"unavailable\"},\"curvatureCalculationMode\":\"yawRateNotUsed\",\"yawRate\":{\"yawRateValue\":0,\"yawRateConfidence\":\"unavailable\"},\"accelerationControl\":{\"brakePedalEngaged\":false,\"gasPedalEngaged\":true,\"emergencyBrakeEngaged\":false,\"collisionWarningEngaged\":false,\"accEngaged\":false,\"cruiseControlEngaged\":false,\"speedLimiterEngaged\":false},\"lanePosition\":0,\"steeringWheelAngle\":{\"steeringWheelAngleValue\":512,\"steeringWheelAngleConfidence\":127},\"lateralAcceleration\":{\"lateralAccelerationValue\":161,\"lateralAccelerationConfidence\":102},\"verticalAcceleration\":{\"verticalAccelerationValue\":161,\"verticalAccelerationConfidence\":102},\"performanceClass\":0,\"cenDsrcTollingZone\":null},\"rsuContainerHighFrequency\":null},\"lowFrequencyContainer\":{\"basicVehicleContainerLowFrequency\":{\"vehicleRole\":\"default_\",\"exteriorLights\":{\"lowBeamHeadlightsOn\":false,\"highBeamHeadlightsOn\":false,\"leftTurnSignalOn\":false,\"rightTurnSignalOn\":false,\"daytimeRunningLightsOn\":false,\"reverseLightOn\":false,\"fogLightOn\":false,\"parkingLightsOn\":false},\"pathHistory\":[]}},\"specialVehicleContainer\":{\"publicTransportContainer\":{\"embarkationStatus\":false,\"ptActivation\":null},\"specialTransportContainer\":null,\"dangerousGoodsContainer\":null,\"roadWorksContainerBasic\":null,\"rescueContainer\":null,\"emergencyContainer\":null,\"safetyCarContainer\":null}}")
        output.write()

        sleep(1) # Write at a rate of one sample every 0.5 seconds, for ex.

    print("Exiting...")
    output.wait()  # Wait for all subscriptions to receive the data before exiting
