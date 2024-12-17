#include "Platforms/DirectX12/Resource/DX12Resource.h"
#include "Graphics/Core/UGraphics.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UResource::UResource(FResourceDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  D3D12_RESOURCE_DESC resourceDesc = wkrtodx12::ConvertFResource(desc.Resource);

  HRESULT hr;
  switch (desc.DescType) {
    case EResourceDescType::kCommitted: {
      D3D12_HEAP_PROPERTIES heapProp =
          wkrtodx12::ConvertFHeapProperty(desc.HeapProp);
      hr = nDevice->CreateCommittedResource(
          &heapProp, wkrtodx12::ConvertEHeapF(desc.HeapFlag), &resourceDesc,
          wkrtodx12::ConvertEResourceStateF(desc.InitialState),
          wkrtodx12::ConvertFClearValue(desc.ClearValue).GetPtr(),
          IID_PPV_ARGS(&m_Resource));
    } break;
    case EResourceDescType::kReserved: {
      hr = nDevice->CreateReservedResource(
          &resourceDesc, wkrtodx12::ConvertEResourceStateF(desc.InitialState),
          wkrtodx12::ConvertFClearValue(desc.ClearValue).GetPtr(),
          IID_PPV_ARGS(&m_Resource));
    } break;
    case EResourceDescType::kPlaced: {
      hr = nDevice->CreatePlacedResource(
          desc.Heap->GetNativeObject(), desc.HeapOffset, &resourceDesc,
          wkrtodx12::ConvertEResourceStateF(desc.InitialState),
          wkrtodx12::ConvertFClearValue(desc.ClearValue).GetPtr(),
          IID_PPV_ARGS(&m_Resource));
    } break;
  }

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Resource");
  WKR_CORE_LOG("Created DX12 Resource!");
}

UResource::~UResource() {
  m_Resource->Release();
}

FResource UResource::GetDesc() {
  D3D12_RESOURCE_DESC desc = m_Resource->GetDesc();
  FResource retDesc = dx12towkr::ConvertFResource(desc);
  return retDesc;
}

}  // namespace wkr::graphics::rhi::dx12
