#pragma once

#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"
#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics::rhi {

struct FAliasingBarrierDesc {
  IResourceHandle resourceBefore;
  IResourceHandle resourceAfter;
};

class UAliasingBarrier {
 public:
  UAliasingBarrier(FAliasingBarrierDesc& desc);

 private:
  rhi::IResourceBarrierHandle m_ResourceView;
};

}  // namespace wkr::graphics::rhi
