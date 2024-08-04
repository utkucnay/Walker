#include <Platforms/DirectX12/Resource/DX12Texture2D.h>

namespace wkr::render::dx12
{
  UTexture2D::~UTexture2D()
  {
    m_resource->Release();
  }

  EResourceState UTexture2D::GetState()
  {
    return EResourceState::Present;
  }

  u64 UTexture2D::GetWidth()
  {
    D3D12_RESOURCE_DESC desc;
    desc = m_resource->GetDesc();
    return desc.Width;
  }

  u64 UTexture2D::GetHeight()
  {
    D3D12_RESOURCE_DESC desc;
    desc = m_resource->GetDesc();
    return desc.Height;
  }
  FSample UTexture2D::GetMSAA()
  {
    D3D12_RESOURCE_DESC desc;
    FSample sDesc;

    desc = m_resource->GetDesc();
    sDesc.count = desc.SampleDesc.Count;
    sDesc.quality = desc.SampleDesc.Quality;
    return sDesc;
  }
}
