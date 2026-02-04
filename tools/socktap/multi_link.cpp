#include "multi_link.hpp"

MultiLink::MultiLink(TransmitPolicy policy)
	: policy_(policy)
{
}

void MultiLink::add_layer(std::unique_ptr<LinkLayer> layer)
{
	layers_.push_back(std::move(layer));
}

void MultiLink::request(const vanetza::access::DataRequest& request, std::unique_ptr<vanetza::ChunkPacket> packet)
{
	switch (policy_) {
		case TransmitPolicy::All:
			for (size_t i = 0; i < layers_.size(); ++i) {
				if (i == layers_.size() - 1) {
					layers_[i]->request(request, std::move(packet));
				} else {
					auto clone = std::make_unique<vanetza::ChunkPacket>(*packet);
					layers_[i]->request(request, std::move(clone));
				}
			}
			break;
		case TransmitPolicy::Primary:
			if (!layers_.empty()) {
				layers_[0]->request(request, std::move(packet));
			}
			break;
	}
}

void MultiLink::indicate(IndicationCallback callback)
{
	callback_ = callback;
	for (auto& layer : layers_) {
		layer->indicate(callback_);
	}
}

void MultiLink::set_source_address(const vanetza::MacAddress& address)
{
	for (auto& layer : layers_) {
		layer->set_source_address(address);
	}
}
