// jer_rj_encode.cpp - ASN.1 to RapidJSON encoding
#include "jer_rj_encode.hpp"
#include "jer_rj_encode_types.hpp"
#include "jer_rj_context.hpp"

#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

namespace vanetza {
namespace asn1 {
namespace rj {

rapidjson::Value jer_encode_rj(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    rapidjson::Document::AllocatorType& allocator)
{
    EncodeContext ctx(allocator);
    return encode_any(td, struct_ptr, ctx);
}

rapidjson::Document jer_encode_rj_doc(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr)
{
    rapidjson::Document doc;
    auto& alloc = doc.GetAllocator();

    EncodeContext ctx(alloc);
    rapidjson::Value json = encode_any(td, struct_ptr, ctx);

    // Move the Value into the Document (Document IS-A Value)
    doc.Swap(json);

    return doc;
}

std::string jer_encode_rj_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr)
{
    rapidjson::Document doc;
    auto& alloc = doc.GetAllocator();

    rapidjson::Value json = jer_encode_rj(td, struct_ptr, alloc);

    rapidjson::StringBuffer buffer;
    buffer.Reserve(4096);  // Pre-allocate for typical message size
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    json.Accept(writer);

    return std::string(buffer.GetString(), buffer.GetSize());
}

void jer_stringify(const rapidjson::Value& json, rapidjson::StringBuffer& buffer)
{
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    json.Accept(writer);
}

} // namespace rj
} // namespace asn1
} // namespace vanetza
