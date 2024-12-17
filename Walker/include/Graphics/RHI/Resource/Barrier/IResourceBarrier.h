#pragma once

#include "Graphics/RHI/Resource/Barrier/ResourceBarrierType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FResourceBarrierDesc {
  EResourceBarrierType Type = EResourceBarrierType::kTransition;
  EResourceBarrierF Flag = EResourceBarrierF::kNone;

  FResourceTransitionBarrier Transition;
  FResourceAliasingBarrier Aliasing;
  FResourceUAVBarrier UAV;
};

class WALKER_API IResourceBarrier {
 public:
  virtual ~IResourceBarrier() = default;

 public:
  virtual FResourceBarrierDesc GetDesc() = 0;
  virtual NativeObject GetNativeObject() = 0;
};

using IResourceBarrierHandle = mem::TRef<IResourceBarrier>;

}  // namespace wkr::graphics::rhi
