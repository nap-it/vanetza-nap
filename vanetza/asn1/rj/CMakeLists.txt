# vanetza/asn1/rj/CMakeLists.txt

set(RJ_SOURCES
    # Encoder sources
    jer_rj_encode.cpp
    encoders/dispatcher.cpp
    encoders/integer_rj.cpp
    encoders/sequence_rj.cpp
    encoders/choice_rj.cpp
    encoders/sequence_of_rj.cpp
    encoders/boolean_rj.cpp
    encoders/enumerated_rj.cpp
    encoders/string_rj.cpp
    encoders/bitstring_rj.cpp

    # Decoder sources
    jer_rj_decode.cpp
    decoders/dispatcher.cpp
    decoders/integer_rj.cpp
    decoders/sequence_rj.cpp
    decoders/choice_rj.cpp
    decoders/sequence_of_rj.cpp
    decoders/boolean_rj.cpp
    decoders/enumerated_rj.cpp
    decoders/string_rj.cpp
    decoders/bitstring_rj.cpp


    # Shared
    transformations/jer_transformations.cpp
    bitnames/jer_bitnames.cpp
)

set(RJ_HEADERS
    jer_rj_encode.hpp
    jer_rj_decode.hpp
    jer_rj_encode_types.hpp
    jer_rj_decode_types.hpp
    jer_rj_context.hpp
    transformations/jer_transformations.hpp
    bitnames/jer_bitnames.hpp
)

add_library(asn1_rj ${RJ_SOURCES} ${RJ_HEADERS})

target_include_directories(asn1_rj
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../support
)

# Find RapidJSON - try system first, fallback to vendor directory
find_package(RapidJSON QUIET)
if(RapidJSON_FOUND)
    target_include_directories(asn1_rj SYSTEM PUBLIC ${RAPIDJSON_INCLUDE_DIRS})
else()
    # Fallback: look for vendor/rapidjson or tools/socktap/rapidjson
    # Check both include/rapidjson/rapidjson.h and rapidjson.h (flat structure)
    set(RAPIDJSON_VENDOR_DIRS
        ${PROJECT_SOURCE_DIR}/vendor/rapidjson/include
        ${PROJECT_SOURCE_DIR}/tools/socktap/rapidjson/include
    )
    set(RAPIDJSON_FLAT_DIRS
        ${PROJECT_SOURCE_DIR}/vendor/rapidjson
        ${PROJECT_SOURCE_DIR}/tools/socktap/rapidjson
    )
    # Check standard structure: dir/rapidjson/rapidjson.h
    foreach(RJPATH ${RAPIDJSON_VENDOR_DIRS})
        if(EXISTS ${RJPATH}/rapidjson/rapidjson.h)
            message(STATUS "Using vendored RapidJSON from ${RJPATH}")
            target_include_directories(asn1_rj SYSTEM PUBLIC ${RJPATH})
            set(RapidJSON_FOUND TRUE)
            break()
        endif()
    endforeach()
    # Check flat structure: dir/rapidjson.h (include parent so #include <rapidjson/...> works)
    if(NOT RapidJSON_FOUND)
        foreach(RJPATH ${RAPIDJSON_FLAT_DIRS})
            if(EXISTS ${RJPATH}/rapidjson.h)
                get_filename_component(RJPARENT ${RJPATH} DIRECTORY)
                message(STATUS "Using vendored RapidJSON from ${RJPARENT} (flat)")
                target_include_directories(asn1_rj SYSTEM PUBLIC ${RJPARENT})
                set(RapidJSON_FOUND TRUE)
                break()
            endif()
        endforeach()
    endif()
    if(NOT RapidJSON_FOUND)
        message(FATAL_ERROR "RapidJSON not found. Install it or place it in vendor/rapidjson")
    endif()
endif()

# Link to asn1 support library (for asn1c type definitions)
target_link_libraries(asn1_rj PUBLIC asn1_support)

# Require C++17
target_compile_features(asn1_rj PUBLIC cxx_std_17)

# Compiler warnings
target_compile_options(asn1_rj PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
)