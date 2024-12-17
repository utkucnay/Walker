#pragma once

namespace wkr::graphics::rhi {

enum class WALKER_API EDescriptorHeapF {
  kNone = 0,
  kShaderVisable = 0x1,
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(EDescriptorHeapF)

enum class WALKER_API EDescriptorHeapType {
  kCBV_SRV_UAV = 0,
  kSampler,
  kRTV,
  kDSV,
  kNumTypes,
};

}  // namespace wkr::graphics::rhi
