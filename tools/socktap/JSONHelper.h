//
// Created by rrosmaninho on 9/2/21.
//

//
// Created by Emrah Ayanoglu on 01.09.19.
//

#ifndef MQTT_HELPER_JSONHELPER_H
#define MQTT_HELPER_JSONHELPER_H

#include <string>
#include <nlohmann/json.hpp>

class JSONHelper{
public:
    static bool fromPayload(const std::string&, nlohmann::json&);
    static bool toPayload(nlohmann::json&, std::string&);
private:
    JSONHelper() = default;
    ~JSONHelper() = default;
};

#endif //MQTT_HELPER_JSONHELPER_H
