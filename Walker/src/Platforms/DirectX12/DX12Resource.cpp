#include <Platforms/DirectX12/Core/DX12TypeMap.h>
#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Resource.h>

namespace wkr::render::dx12
{
  UResource::UResource(FResourceDesc& desc)
  {
    ID3D12Device* nDevice = URenderer::GetDefaultDevice().GetNativeObject();

    switch (desc.descType)
    {
      case EResourceDescType::Committed:
      {
        nDevice->CreateCommittedResource(
            ConvertFHeapDesc(desc.heapDesc).GetPtr(),
            ConvertEHeapF(desc.heapDesc.m_flag),
            ConvertFResource(desc.resource).GetPtr(),
            ConvertEResourceState(desc.initialState),
            ConvertFClearValue(desc.clearValue).GetPtr(),
            IID_PPV_ARGS(&m_resource));
      } break;
      case EResourceDescType::Reserved:
      {
        nDevice->CreateReservedResource(
            ConvertFResource(desc.resource).GetPtr(),
            ConvertEResourceState(desc.initialState),
            ConvertFClearValue(desc.clearValue).GetPtr(),
            IID_PPV_ARGS(&m_resource));
      } break;
      case EResourceDescType::Placed:
      {
        nDevice->CreatePlacedResource(
            desc.heap->GetNativeObject(),
            desc.heapOffset,
            ConvertFResource(desc.resource).GetPtr(),
            ConvertEResourceState(desc.initialState),
            ConvertFClearValue(desc.clearValue).GetPtr(),
            IID_PPV_ARGS(&m_resource));
      } break;
    }

  }

  UResource::~UResource()
  {
    m_resource->Release();
  }
}
