#pragma once

#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics::rhi {

enum class WALKER_API EResourceBarrierType {
  kTransition = 0,
  kAliasing,
  kUAV,
};

enum class WALKER_API EResourceBarrierF {
  kNone = 0,
  kBeginOnly = 0x1,
  kEndOnly = 0x2,
};

struct WALKER_API FResourceTransitionBarrier {
  IResourceHandle Resource;
  u32 Subresource;
  EResourceStateF StateBefore;
  EResourceStateF StateAfter;
};

struct WALKER_API FResourceAliasingBarrier {
  IResourceHandle ResourceBefore;
  IResourceHandle ResourceAfter;
};

struct WALKER_API FResourceUAVBarrier {
  IResourceHandle Resource;
};

}  // namespace wkr::graphics::rhi
