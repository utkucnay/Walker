#include <Platforms/DirectX12/Resource/DX12Texture2D.h>

namespace wkr::render::rsc
{
  uint64_t DX12Texture2D::GetWidth()
  {
    D3D12_RESOURCE_DESC desc;
    desc = m_resource->GetDesc();
    return desc.Width;
  }

  uint64_t DX12Texture2D::GetHeight()
  {
    D3D12_RESOURCE_DESC desc;
    desc = m_resource->GetDesc();
    return desc.Height;
  }
  SampleDesc DX12Texture2D::GetMSAA()
  {
    D3D12_RESOURCE_DESC desc;
    SampleDesc sDesc;

    desc = m_resource->GetDesc();
    sDesc.count = desc.SampleDesc.Count;
    sDesc.quality = desc.SampleDesc.Quality;
    return sDesc;
  }
}