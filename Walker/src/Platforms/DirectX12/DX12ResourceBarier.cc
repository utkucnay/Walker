#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"
#include "Graphics/RHI/Resource/Barrier/ResourceBarrierType.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"
#include "Platforms/DirectX12/Resource/DX12Resource.h"
#include "Platforms/DirectX12/ResourceBarrier/DX12ResourceBarrier.h"

namespace wkr::graphics::rhi::dx12 {

UResourceBarrier::UResourceBarrier(FResourceBarrierDesc& desc) {
  m_ResourceBarrier.Type = wkrtodx12::ConvertEResourceBarrierType(desc.Type);
  m_ResourceBarrier.Flags = wkrtodx12::ConvertEResourceBarrierF(desc.Flag);

  switch (desc.Type) {
    case EResourceBarrierType::kTransition: {
      m_ResourceBarrier.Transition.pResource =
          desc.Transition.Resource->GetNativeObject();
      m_ResourceBarrier.Transition.StateBefore =
          wkrtodx12::ConvertEResourceStateF(desc.Transition.StateBefore);
      m_ResourceBarrier.Transition.StateAfter =
          wkrtodx12::ConvertEResourceStateF(desc.Transition.StateAfter);
      m_ResourceBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    } break;
    case EResourceBarrierType::kUAV: {
      m_ResourceBarrier.UAV.pResource = desc.UAV.Resource->GetNativeObject();
    } break;
    case EResourceBarrierType::kAliasing: {
      m_ResourceBarrier.Aliasing.pResourceBefore =
          desc.Aliasing.ResourceBefore->GetNativeObject();
      m_ResourceBarrier.Aliasing.pResourceAfter =
          desc.Aliasing.ResourceAfter->GetNativeObject();
    } break;
  }
}

FResourceBarrierDesc UResourceBarrier::GetDesc() {
  FResourceBarrierDesc desc;

  desc.Type = dx12towkr::ConvertEResourceBarrierType(m_ResourceBarrier.Type);
  desc.Flag = dx12towkr::ConvertEResourceBarrierF(m_ResourceBarrier.Flags);

  switch (desc.Type) {
    case EResourceBarrierType::kTransition: {
      desc.Transition.Resource =
          new UResource(m_ResourceBarrier.Transition.pResource);
      desc.Transition.StateBefore = dx12towkr::ConvertEResourceStateF(
          m_ResourceBarrier.Transition.StateBefore);
      desc.Transition.StateAfter = dx12towkr::ConvertEResourceStateF(
          m_ResourceBarrier.Transition.StateAfter);
    } break;
    case EResourceBarrierType::kUAV: {
      desc.UAV.Resource = new UResource(m_ResourceBarrier.UAV.pResource);
    } break;
    case EResourceBarrierType::kAliasing: {
      desc.Aliasing.ResourceAfter =
          new UResource(m_ResourceBarrier.Aliasing.pResourceAfter);
      desc.Aliasing.ResourceBefore =
          new UResource(m_ResourceBarrier.Aliasing.pResourceBefore);
    } break;
  }
  return desc;
}

}  // namespace wkr::graphics::rhi::dx12
