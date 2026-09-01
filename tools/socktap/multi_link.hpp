#ifndef MULTI_LINK_HPP_
#define MULTI_LINK_HPP_

#include "link_layer.hpp"
#include <memory>
#include <vector>

class MultiLink : public LinkLayer
{
public:
	enum class TransmitPolicy {
		All,
		Primary
	};

	MultiLink(TransmitPolicy policy = TransmitPolicy::All);

	void add_layer(std::unique_ptr<LinkLayer> layer);

	void request(const vanetza::access::DataRequest&, std::unique_ptr<vanetza::ChunkPacket>) override;
	void indicate(IndicationCallback) override;
	void set_source_address(const vanetza::MacAddress&) override;

private:
	std::vector<std::unique_ptr<LinkLayer>> layers_;
	TransmitPolicy policy_;
	IndicationCallback callback_;
};

#endif /* MULTI_LINK_HPP_ */
