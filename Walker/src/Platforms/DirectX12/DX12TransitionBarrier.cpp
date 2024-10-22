#include "Platforms/DirectX12/ResourceBarrier/DX12TransitionBarrier.h"

namespace wkr::render::dx12 {

UTransitionBarrier::UTransitionBarrier(FTransitionBarrierDesc& desc) {
  auto nResource =
      static_cast<ID3D12Resource*>(desc.m_resource->GetNativeObject());
  auto nBeforeState = static_cast<D3D12_RESOURCE_STATES>(desc.m_beforeState);
  auto nAfterState = static_cast<D3D12_RESOURCE_STATES>(desc.m_afterState);
  m_resourceBarrier = CD3DX12_RESOURCE_BARRIER::Transition(
      nResource, nBeforeState, nAfterState);
}

UTransitionBarrier::~UTransitionBarrier() {}

}  // namespace wkr::render::dx12
