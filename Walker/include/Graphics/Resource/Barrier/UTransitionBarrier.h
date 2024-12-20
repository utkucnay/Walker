#pragma once

#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

struct FTransitionBarrierDesc {
  rhi::IResourceHandle Resource;
  EResourceStateF BeforeState;
  EResourceStateF AfterState;
};

class UTransitionBarrier {
 public:
  explicit UTransitionBarrier(FTransitionBarrierDesc& desc);

 public:
  rhi::IResourceBarrierHandle& GetResourceBarrier() {
    return m_ResourceBarrier;
  }

  FTransitionBarrierDesc GetDesc();
  UTransitionBarrier Reverse();

 private:
  rhi::IResourceBarrierHandle m_ResourceBarrier;
};

}  // namespace wkr::graphics
