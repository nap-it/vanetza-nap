//
// Created by rrosmaninho on 9/2/21.
//

//
// Created by Emrah Ayanoglu on 01.09.19.
//

#include <iostream>
#include "JSONHelper.h"

bool JSONHelper::fromPayload(const std::string& payload, nlohmann::json& jsonObj) {
    try{
        jsonObj = nlohmann::json::parse(payload);
        return true;
    }
    catch(const nlohmann::detail::parse_error& err)
    {
        std::cout << err.what() << std::endl;
        return false;
    }
}

bool JSONHelper::toPayload(nlohmann::json& jsonPayload, std::string& payload) {
    try{
        payload = jsonPayload.dump();
        return true;
    }
    catch (const nlohmann::detail::exception& ex){
        std::cout << ex.what() << std::endl;
        return false;
    }
}

