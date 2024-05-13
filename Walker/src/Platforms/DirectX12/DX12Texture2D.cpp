#include <Platforms/DirectX12/Resource/DX12Texture2D.h>

namespace wkr::render::rsc
{
  UDX12Texture2D::~UDX12Texture2D()
  {
    m_resource->Release();
  }

  IResource::State UDX12Texture2D::GetState()
  {
    return IResource::State::Present;
  }

  u64 UDX12Texture2D::GetWidth()
  {
    D3D12_RESOURCE_DESC desc;
    desc = m_resource->GetDesc();
    return desc.Width;
  }

  u64 UDX12Texture2D::GetHeight()
  {
    D3D12_RESOURCE_DESC desc;
    desc = m_resource->GetDesc();
    return desc.Height;
  }
  FSample UDX12Texture2D::GetMSAA()
  {
    D3D12_RESOURCE_DESC desc;
    FSample sDesc;

    desc = m_resource->GetDesc();
    sDesc.count = desc.SampleDesc.Count;
    sDesc.quality = desc.SampleDesc.Quality;
    return sDesc;
  }
}
