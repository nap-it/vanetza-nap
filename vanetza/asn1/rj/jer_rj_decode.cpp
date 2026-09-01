// jer_rj_decode.cpp
#include "jer_rj_decode.hpp"
#include "jer_rj_decode_types.hpp"

extern "C" {
#include "asn_internal.h"
#include "asn_application.h"
}

#include <rapidjson/document.h>

namespace vanetza {
namespace asn1 {
namespace rj {

DecodeResult jer_decode_rj(
    const asn_TYPE_descriptor_t* td,
    const rapidjson::Value& json,
    bool verbose)
{
    DecodeResult result = {nullptr, nullptr, ""};

    if (!td) {
        result.error = "Null type descriptor";
        if (verbose) result.verbose_error = "Error: Null type descriptor\nIn: (root)";
        return result;
    }

    // Allocate the root structure using asn1c allocator
    size_t struct_size = get_struct_size(td);
    if (struct_size == 0) {
        result.error = "Unknown struct size for type";
        if (verbose) result.verbose_error = "Error: Unknown struct size for type\nIn: (root)";
        return result;
    }
    void* structure = CALLOC(1, struct_size);
    if (!structure) {
        result.error = "Memory allocation failed";
        if (verbose) result.verbose_error = "Error: Memory allocation failed\nIn: (root)";
        return result;
    }

    // Create decode context with verbose mode
    DecodeContext ctx;
    ctx.verbose = verbose;

    // Decode recursively
    if (!decode_any(td, structure, json, ctx)) {
        // Decode failed - free partially allocated structure
        ASN_STRUCT_FREE(*td, structure);
        result.error = ctx.error ? ctx.error : "Decode failed";
        if (verbose) {
            result.verbose_error = ctx.get_verbose_error();
        }
        return result;
    }

    result.structure = structure;
    return result;
}

DecodeResult jer_decode_rj_string(
    const asn_TYPE_descriptor_t* td,
    const char* json_string,
    bool verbose)
{
    DecodeResult result = {nullptr, nullptr, ""};

    if (!json_string) {
        result.error = "Null JSON string";
        if (verbose) result.verbose_error = "Error: Null JSON string\nIn: (root)";
        return result;
    }

    rapidjson::Document doc;
    doc.Parse(json_string);

    if (doc.HasParseError()) {
        result.error = "JSON parse error";
        if (verbose) {
            result.verbose_error = "Error: JSON parse error at offset " +
                std::to_string(doc.GetErrorOffset()) + "\nIn: (root)";
        }
        return result;
    }

    return jer_decode_rj(td, doc, verbose);
}

bool jer_decode_rj_inplace(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    std::string* verbose_error)
{
    if (!td || !struct_ptr) {
        if (verbose_error) {
            *verbose_error = "Error: Null type descriptor or struct pointer\nIn: (root)";
        }
        return false;
    }

    DecodeContext ctx;
    ctx.verbose = (verbose_error != nullptr);

    bool success = decode_any(td, struct_ptr, json, ctx);

    if (!success && verbose_error) {
        *verbose_error = ctx.get_verbose_error();
    }

    return success;
}

} // namespace rj
} // namespace asn1
} // namespace vanetza
