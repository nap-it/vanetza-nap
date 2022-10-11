cmake_minimum_required(VERSION 3.1)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-narrowing -I/usr/include/libnl3 -lnl-genl-3 -lnl-3 -ldl")

if(NOT TARGET Boost::system)
    message(STATUS "Skip build of socktap because of missing Boost::system dependency")
    return()
endif()

if(NOT TARGET Boost::program_options)
    message(STATUS "Skip build of socktap because of missing Boost::program_options dependency")
    return()
endif()

find_package(Threads REQUIRED)

add_executable(socktap
    asn1json.cpp
    config_reader.hpp
    config.hpp config.cpp
    mqtt.h mqtt.cpp
    dds.h dds.cpp
    application.cpp
    cam_application.cpp
    denm_application.cpp
    cpm_application.cpp
    vam_application.cpp
    spatem_application.cpp
    mapem_application.cpp
    dcc_passthrough.cpp
    ethernet_device.cpp
    link_layer.cpp
    main.cpp
    positioning.cpp
    rssi_reader.cpp
    raw_socket_link.cpp
    router_context.cpp
    security.cpp
    time_trigger.cpp)

target_link_libraries(socktap PUBLIC mosquittopp)

target_link_libraries(socktap PUBLIC Boost::system Boost::program_options Threads::Threads vanetza)
install(TARGETS socktap EXPORT ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

option(SOCKTAP_WITH_COHDA_LLC "Use Cohda LLC API for socktap" ${COHDA_FOUND})
if(SOCKTAP_WITH_COHDA_LLC)
    find_package(Cohda MODULE REQUIRED)
    target_compile_definitions(socktap PUBLIC "SOCKTAP_WITH_COHDA_LLC")
    target_include_directories(socktap PUBLIC ${COHDA_INCLUDE_DIRS})
    target_sources(socktap PRIVATE cohda.cpp cohda_link.cpp)
endif()

find_package(GPS QUIET)
option(SOCKTAP_WITH_GPSD "Enable gpsd positioning for socktap" true)
if(SOCKTAP_WITH_GPSD)
    find_package(GPS REQUIRED)
    target_compile_definitions(socktap PUBLIC "SOCKTAP_WITH_GPSD")
    target_link_libraries(socktap PUBLIC GPS::GPS)
    target_sources(socktap PRIVATE gps_position_provider.cpp)
endif()

set(JSON_ImplicitConversions ON)

find_package(prometheus-cpp CONFIG REQUIRED)

if(PROMETHEUS_CPP_ENABLE_PUSH)
  target_link_libraries(socktap PRIVATE prometheus-cpp::push)
endif()

if(PROMETHEUS_CPP_ENABLE_PULL)
  target_link_libraries(socktap PRIVATE prometheus-cpp::pull)
endif()
