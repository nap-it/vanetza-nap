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
        output.instance.set_string("message", "{\"camParameters\":{\"basicContainer\":{\"referencePosition\":{\"altitude\":{\"altitudeConfidence\":15,\"altitudeValue\":800001},\"latitude\":400000000,\"longitude\":-80000000,\"positionConfidenceEllipse\":{\"semiMajorConfidence\":4095,\"semiMajorOrientation\":3601,\"semiMinorConfidence\":4095}},\"stationType\":5},\"highFrequencyContainer\":{\"basicVehicleContainerHighFrequency\":{\"accelerationControl\":{\"accEngaged\":true,\"brakePedalEngaged\":true,\"collisionWarningEngaged\":true,\"cruiseControlEngaged\":true,\"emergencyBrakeEngaged\":true,\"gasPedalEngaged\":false,\"speedLimiterEngaged\":true},\"curvature\":{\"curvatureConfidence\":7,\"curvatureValue\":1023},\"curvatureCalculationMode\":0,\"driveDirection\":0,\"heading\":{\"headingConfidence\":127,\"headingValue\":3601},\"longitudinalAcceleration\":{\"longitudinalAccelerationConfidence\":0,\"longitudinalAccelerationValue\":0},\"speed\":{\"speedConfidence\":127,\"speedValue\":16383},\"vehicleLength\":{\"vehicleLengthConfidenceIndication\":0,\"vehicleLengthValue\":100},\"vehicleWidth\":30,\"yawRate\":{\"yawRateConfidence\":0,\"yawRateValue\":0}}}},\"generationDeltaTime\":2907}")
        output.write()

        sleep(1) # Write at a rate of one sample every 0.5 seconds, for ex.

    print("Exiting...")
    output.wait()  # Wait for all subscriptions to receive the data before exiting
