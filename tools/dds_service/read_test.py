import rticonnextdds_connector as rti

with rti.open_connector(
        config_name="participant_library::its_app",
        url="./Vanetza_DDS_Spec.xml") as connector:

    input = connector.get_input("its_subscriber::vanetza/out/cam_full")

    print("Waiting for publications...")
    input.wait_for_publications() # wait for at least one matching publication

    print("Waiting for data...")
    for i in range(1, 500):
        input.wait() # wait for data on this input
        input.take()
        for sample in input.samples.valid_data_iter:
            data = sample.get_dictionary()
            print(data["message"])
