#pragma once

namespace wkr::graphics::rhi {

enum class WALKER_API ECommandType {
  kDirect = 0,
  kBundle = 1,
  kCompute = 2,
  kCopy = 3,
  kVideoDecode = 4,
  kVideoProcess = 5,
  kVideoEncode = 6,
  kNone = 7,
};

enum class WALKER_API ECommandQueueF {
  kNone = 0,
  kDisableGPUTimeout = 0x1,
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(ECommandQueueF)

enum class WALKER_API ECommandQueuePriority {
  kNormal = 0,
  kHigh = 100,
  kRealtime = 10000,
};

}  // namespace wkr::graphics::rhi
