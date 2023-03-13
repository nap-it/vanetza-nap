#include "config.hpp"

message_config_t read_message_config(INIReader reader, string env_prefix, string ini_section) {
    message_config_t res = {
        getenv((env_prefix + "_ENABLED").c_str()) == NULL ? reader.GetBoolean(ini_section, "enabled", true) : (strcmp(getenv((env_prefix + "_ENABLED").c_str()), "true") == 0),
        getenv((env_prefix + "_PERIODICITY").c_str()) == NULL ? reader.GetInteger(ini_section, "periodicity", 0) : stoi(getenv((env_prefix + "_PERIODICITY").c_str())),
        getenv((env_prefix + "_TOPIC_IN").c_str()) == NULL ? reader.Get(ini_section, "topic_in", "target/none") : getenv((env_prefix + "_TOPIC_IN").c_str()),
        getenv((env_prefix + "_TOPIC_OUT").c_str()) == NULL ? reader.Get(ini_section, "topic_out", "vanetza/message") : getenv((env_prefix + "_TOPIC_OUT").c_str()),
        getenv((env_prefix + "_TOPIC_TIME").c_str()) == NULL ? reader.Get(ini_section, "topic_time", "vanetza/time") : getenv((env_prefix + "_TOPIC_TIME").c_str()),
        getenv((env_prefix + "_UDP_OUT_ADDR").c_str()) == NULL ? reader.Get(ini_section, "udp_out_addr", "127.0.0.1") : getenv((env_prefix + "_UDP_OUT_ADDR").c_str()),
        getenv((env_prefix + "_UDP_OUT_PORT").c_str()) == NULL ? reader.GetInteger(ini_section, "udp_out_port", 0) : stoi(getenv((env_prefix + "_UDP_OUT_PORT").c_str())),
        getenv((env_prefix + "_MQTT_ENABLED").c_str()) == NULL ? reader.GetBoolean(ini_section, "mqtt_enabled", true) : (strcmp(getenv((env_prefix + "_MQTT_ENABLED").c_str()), "true") == 0),
        getenv((env_prefix + "_MQTT_TIME_ENABLED").c_str()) == NULL ? reader.GetBoolean(ini_section, "mqtt_time_enabled", true) : (strcmp(getenv((env_prefix + "_MQTT_TIME_ENABLED").c_str()), "true") == 0),
        getenv((env_prefix + "_DDS_ENABLED").c_str()) == NULL ? reader.GetBoolean(ini_section, "dds_enabled", true) : (strcmp(getenv((env_prefix + "_DDS_ENABLED").c_str()), "true") == 0),
    };
    return res;
}

void read_config(config_t* config_s, string path) {
    INIReader reader(path);

    config_s->station_id = getenv("VANETZA_STATION_ID") == NULL ? reader.GetInteger("station", "id", 99) : stoi(getenv("VANETZA_STATION_ID"));
    config_s->station_type = getenv("VANETZA_STATION_TYPE") == NULL ? reader.GetInteger("station", "type", 15) : stoi(getenv("VANETZA_STATION_TYPE"));
    config_s->remote_mqtt_prefix = config_s->station_type == 15 ? "p" : "obu";
    config_s->mac_address = getenv("VANETZA_MAC_ADDRESS") == NULL ? reader.Get("station", "mac_address", "") : getenv("VANETZA_MAC_ADDRESS");
    config_s->beacons_enabled = getenv("VANETZA_BEACONS_ENABLED") == NULL ? reader.GetBoolean("station", "beacons_enabled", true) : (strcmp((getenv("VANETZA_BEACONS_ENABLED")), "true") == 0);
    config_s->use_hardcoded_gps = getenv("VANETZA_USE_HARDCODED_GPS") == NULL ? reader.GetBoolean("station", "use_hardcoded_gps", true) : (strcmp((getenv("VANETZA_USE_HARDCODED_GPS")), "true") == 0);
    config_s->latitude = getenv("VANETZA_LATITUDE") == NULL ? reader.GetReal("station", "latitude", 40) : stod(getenv("VANETZA_LATITUDE"));
    config_s->longitude = getenv("VANETZA_LONGITUDE") == NULL ? reader.GetReal("station", "longitude", -8) : stod(getenv("VANETZA_LONGITUDE"));
    config_s->length = getenv("VANETZA_LENGTH") == NULL ? reader.GetReal("station", "length", 10) : stod(getenv("VANETZA_LENGTH"));
    config_s->width = getenv("VANETZA_WIDTH") == NULL ? reader.GetReal("station", "width", 3) : stod(getenv("VANETZA_WIDTH"));
    config_s->interface = getenv("VANETZA_INTERFACE") == NULL ? reader.Get("general", "interface", "wlan0") : getenv("VANETZA_INTERFACE");
    config_s->local_mqtt_broker = getenv("VANETZA_LOCAL_MQTT_BROKER") == NULL ? reader.Get("general", "local_mqtt_broker", "127.0.0.1") : getenv("VANETZA_LOCAL_MQTT_BROKER");
    config_s->local_mqtt_port = getenv("VANETZA_LOCAL_MQTT_PORT") == NULL ? reader.GetInteger("general", "local_mqtt_port", 1883) : stoi(getenv("VANETZA_LOCAL_MQTT_PORT"));
    config_s->remote_mqtt_broker = getenv("VANETZA_REMOTE_MQTT_BROKER") == NULL ? reader.Get("general", "remote_mqtt_broker", "") : getenv("VANETZA_REMOTE_MQTT_BROKER");
    config_s->remote_mqtt_port = getenv("VANETZA_REMOTE_MQTT_PORT") == NULL ? reader.GetInteger("general", "remote_mqtt_port", 0) : stoi(getenv("VANETZA_REMOTE_MQTT_PORT"));
    config_s->remote_mqtt_username = getenv("VANETZA_REMOTE_MQTT_USERNAME") == NULL ? reader.Get("general", "remote_mqtt_username", "") : getenv("VANETZA_REMOTE_MQTT_USERNAME");
    config_s->remote_mqtt_password = getenv("VANETZA_REMOTE_MQTT_PASSWORD") == NULL ? reader.Get("general", "remote_mqtt_password", "") : getenv("VANETZA_REMOTE_MQTT_PASSWORD");
    config_s->gpsd_host = getenv("VANETZA_GPSD_HOST") == NULL ? reader.Get("general", "gpsd_host", "127.0.0.1") : getenv("VANETZA_GPSD_HOST");
    config_s->gpsd_port = getenv("VANETZA_GPSD_PORT") == NULL ? reader.Get("general", "gpsd_port", "2947") : getenv("VANETZA_GPSD_PORT");
    config_s->prometheus_port = getenv("VANETZA_PROMETHEUS_PORT") == NULL ? reader.GetInteger("general", "prometheus_port", 9100) : stoi(getenv("VANETZA_PROMETHEUS_PORT"));
    config_s->rssi_enabled = getenv("VANETZA_RSSI_ENABLED") == NULL ? reader.GetBoolean("general", "rssi_enabled", true) : (strcmp((getenv("VANETZA_RSSI_ENABLED")), "true") == 0);
    config_s->ignore_own_messages = getenv("VANETZA_IGNORE_OWN_MESSAGES") == NULL ? reader.GetBoolean("general", "ignore_own_messages", true) : (strcmp((getenv("VANETZA_IGNORE_OWN_MESSAGES")), "true") == 0);
    config_s->ignore_rsu_messages = getenv("VANETZA_IGNORE_RSU_MESSAGES") == NULL ? reader.GetBoolean("general", "ignore_rsu_messages", false) : (strcmp((getenv("VANETZA_IGNORE_RSU_MESSAGES")), "true") == 0);
    config_s->to_dds_key = getenv("VANETZA_TO_DDS_KEY") == NULL ? reader.GetInteger("general", "to_dds_key", 6060) : stoi(getenv("VANETZA_TO_DDS_KEY"));
    config_s->from_dds_key = getenv("VANETZA_FROM_DDS_KEY") == NULL ? reader.GetInteger("general", "from_dds_key", 6061) : stoi(getenv("VANETZA_FROM_DDS_KEY"));
    config_s->enable_json_prints = getenv("VANETZA_ENABLE_JSON_PRINTS") == NULL ? reader.GetBoolean("general", "enable_json_prints", true) : (strcmp((getenv("VANETZA_ENABLE_JSON_PRINTS")), "true") == 0);
    config_s->cam = read_message_config(reader, "VANETZA_CAM", "cam");
    config_s->denm = read_message_config(reader, "VANETZA_DENM", "denm");
    config_s->cpm = read_message_config(reader, "VANETZA_CPM", "cpm");
    config_s->vam = read_message_config(reader, "VANETZA_VAM", "vam");
    config_s->spatem = read_message_config(reader, "VANETZA_SPATEM", "spatem");
    config_s->mapem = read_message_config(reader, "VANETZA_MAPEM", "mapem");
    config_s->full_cam_topic_in = getenv("VANETZA_CAM_FULL_TOPIC_IN") == NULL ? reader.Get("cam", "full_topic_in", "") : getenv("VANETZA_CAM_FULL_TOPIC_IN");
    config_s->full_cam_topic_out = getenv("VANETZA_CAM_FULL_TOPIC_OUT") == NULL ? reader.Get("cam", "full_topic_out", "") : getenv("VANETZA_CAM_FULL_TOPIC_OUT");
    config_s->full_vam_topic_in = getenv("VANETZA_VAM_FULL_TOPIC_IN") == NULL ? reader.Get("vam", "full_topic_in", "") : getenv("VANETZA_VAM_FULL_TOPIC_IN");
    config_s->full_vam_topic_out = getenv("VANETZA_VAM_FULL_TOPIC_OUT") == NULL ? reader.Get("vam", "full_topic_out", "") : getenv("VANETZA_VAM_FULL_TOPIC_OUT");
    config_s->own_cam_topic_out = getenv("VANETZA_CAM_OWN_TOPIC_OUT") == NULL ? reader.Get("cam", "own_topic_out", "") : getenv("VANETZA_CAM_OWN_TOPIC_OUT");
    config_s->own_full_cam_topic_out = getenv("VANETZA_CAM_OWN_FULL_TOPIC_OUT") == NULL ? reader.Get("cam", "own_full_topic_out", "") : getenv("VANETZA_CAM_OWN_FULL_TOPIC_OUT");
}
