#pragma once

#include "Graphics/RHI/Resource/Barrier/ResourceBarrierType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FResourceBarrierDesc {
  EResourceBarrierType Type = EResourceBarrierType::kTransition;
  EResourceBarrierF Flag = EResourceBarrierF::kNone;

  union {
    FResourceTransitionBarrier Transition = {};
    FResourceAliasingBarrier Aliasing;
    FResourceUAVBarrier UAV;
  };
};

class WALKER_API IResourceBarrier {
 public:
  virtual ~IResourceBarrier() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;
};

using IResourceBarrierHandle = mem::TRef<IResourceBarrier>;

}  // namespace wkr::graphics::rhi
