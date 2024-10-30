#include "Platforms/DirectX12/Core/DX12TypeMap.h"
#include "Platforms/DirectX12/Resource/DX12Resource.h"
#include "Graphics/Core/UGraphics.h"

namespace wkr::render::dx12 {

UResource::UResource(FResourceDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  HRESULT hr;
  switch (desc.descType) {
    case EResourceDescType::Committed: {
      hr = nDevice->CreateCommittedResource(
          ConvertFHeapDesc(desc.heapDesc).GetPtr(),
          ConvertEHeapF(desc.heapDesc.m_flag),
          ConvertFResource(desc.resource).GetPtr(),
          ConvertEResourceState(desc.initialState),
          ConvertFClearValue(desc.clearValue).GetPtr(),
          IID_PPV_ARGS(&m_resource));
    } break;
    case EResourceDescType::Reserved: {
      hr = nDevice->CreateReservedResource(
          ConvertFResource(desc.resource).GetPtr(),
          ConvertEResourceState(desc.initialState),
          ConvertFClearValue(desc.clearValue).GetPtr(),
          IID_PPV_ARGS(&m_resource));
    } break;
    case EResourceDescType::Placed: {
      hr = nDevice->CreatePlacedResource(
          desc.heap->GetNativeObject(), desc.heapOffset,
          ConvertFResource(desc.resource).GetPtr(),
          ConvertEResourceState(desc.initialState),
          ConvertFClearValue(desc.clearValue).GetPtr(),
          IID_PPV_ARGS(&m_resource));
    } break;
  }

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Resource");
  WKR_CORE_LOG("Created DX12 Resource!");
}

UResource::~UResource() {
  m_resource->Release();
}

}  // namespace wkr::render::dx12
