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
  UTransitionBarrier(FTransitionBarrierDesc& desc);

 public:
  rhi::IResourceBarrierHandle& GetResourceBarrier() {
    return m_ResourceBarrier;
  }

  FTransitionBarrierDesc GetDesc() {
    rhi::FResourceBarrierDesc barrierDesc = m_ResourceBarrier->GetDesc();
    FTransitionBarrierDesc desc = {
        .Resource = barrierDesc.Transition.Resource,
        .BeforeState = barrierDesc.Transition.StateBefore,
        .AfterState = barrierDesc.Transition.StateAfter,
    };

    return desc;
  }

  UTransitionBarrier Reverse() {
    FTransitionBarrierDesc desc = GetDesc();
    EResourceStateF tmpSwap = desc.BeforeState;
    desc.BeforeState = desc.AfterState;
    desc.AfterState = tmpSwap;
    return UTransitionBarrier(desc);
  }

 private:
  rhi::IResourceBarrierHandle m_ResourceBarrier;
};

}  // namespace wkr::graphics
