#include <vanetza/security/verify_service.hpp>
namespace vanetza
{
namespace security
{

const char* to_string(VerificationReport report)
{
    switch (report) {
        case VerificationReport::Success:
            return "Success";
        case VerificationReport::False_Signature:
            return "False_Signature";
        case VerificationReport::Invalid_Certificate:
            return "Invalid_Certificate";
        case VerificationReport::Revoked_Certificate:
            return "Revoked_Certificate";
        case VerificationReport::Inconsistent_Chain:
            return "Inconsistent_Chain";
        case VerificationReport::Invalid_Timestamp:
            return "Invalid_Timestamp";
        case VerificationReport::Duplicate_Message:
            return "Duplicate_Message";
        case VerificationReport::Invalid_Mobility_Data:
            return "Invalid_Mobility_Data";
        case VerificationReport::Unsigned_Message:
            return "Unsigned_Message";
        case VerificationReport::Signer_Certificate_Not_Found:
            return "Signer_Certificate_Not_Found";
        case VerificationReport::Unsupported_Signer_Identifier_Type:
            return "Unsupported_Signer_Identifier_Type";
        case VerificationReport::Incompatible_Protocol:
            return "Incompatible_Protocol";
        case VerificationReport::Configuration_Problem:
            return "Configuration_Problem";
        case VerificationReport::Verification_Skipped:
            return "Verification_Skipped";
        default:
            return "Unknown";
    }
}

DummyVerifyService::DummyVerifyService(VerificationReport report, CertificateValidity validity) :
    m_report(report), m_validity(validity)
{
}

VerifyConfirm DummyVerifyService::verify(const VerifyRequest& request)
{
    VerifyConfirm confirm;
    confirm.report = m_report;
    confirm.certificate_validity = m_validity;
    confirm.its_aid = get_its_aid(request.secured_message);
    return confirm;
}

} // namespace security
} // namespace vanetza
