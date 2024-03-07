#include <Platforms/DirectX12/ResourceBarrier/DX12TransitionBarrier.h>

namespace wkr::render::rsc::bar
{
  DX12TransitionBarrier::DX12TransitionBarrier(TransitionBarrierBuilder* tbb)
  {
    auto nResource = static_cast<ID3D12Resource*>(tbb->m_resource->GetNativeHandle());
    auto nBeforeState = static_cast<D3D12_RESOURCE_STATES>(tbb->m_beforeState);
    auto nAfterState = static_cast<D3D12_RESOURCE_STATES>(tbb->m_afterState);
    m_resourceBarrier = CD3DX12_RESOURCE_BARRIER::Transition(nResource, nBeforeState, nAfterState);
  }

  DX12TransitionBarrier::~DX12TransitionBarrier() {}
}
