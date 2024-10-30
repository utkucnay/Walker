#pragma once

#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/ResourceBarrier/IResourceBarrier.h"

namespace wkr::graphics::rhi {

struct FAliasingBarrierDesc {
  IResourceHandle resourceBefore;
  IResourceHandle resourceAfter;
};

class IAliasingBarrier : IResourceBarrier {
 public:
  virtual ~IAliasingBarrier() override = default;
};

using IAliasingBarrierHandle = mem::TRef<IAliasingBarrier>;

}  // namespace wkr::graphics::rhi
