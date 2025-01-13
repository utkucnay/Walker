#include "Graphics/Resource/Barrier/UTransitionBarrier.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Factory/IRHIAbstractFactory.h"
#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"
#include "Graphics/RHI/Resource/Barrier/ResourceBarrierType.h"

namespace wkr::graphics {

UTransitionBarrier::UTransitionBarrier(FTransitionBarrierDesc& desc) {
  auto& factory = UGraphicsAPI::GetAbstractFactory();

  rhi::FResourceBarrierDesc nDesc = {
      .Type = rhi::EResourceBarrierType::kTransition,
      .Flag = rhi::EResourceBarrierF::kNone,
      .Transition =
          {
              .Resource = desc.Resource,
              .StateBefore = desc.BeforeState,
              .StateAfter = desc.AfterState,
          },
  };

  m_ResourceBarrier =
      rhi::IResourceBarrierHandle(factory.GetResourceBarrier(nDesc));
}

FTransitionBarrierDesc UTransitionBarrier::GetDesc() {
  rhi::FResourceBarrierDesc barrierDesc = m_ResourceBarrier->GetDesc();

  FTransitionBarrierDesc desc = {
      .Resource = barrierDesc.Transition.Resource,
      .BeforeState = barrierDesc.Transition.StateBefore,
      .AfterState = barrierDesc.Transition.StateAfter,
  };

  return desc;
}

UTransitionBarrier UTransitionBarrier::Reverse() {
  FTransitionBarrierDesc desc = GetDesc();
  EResourceStateF tmpSwap = desc.BeforeState;
  desc.BeforeState = desc.AfterState;
  desc.AfterState = tmpSwap;
  return UTransitionBarrier(desc);
}

}  // namespace wkr::graphics
