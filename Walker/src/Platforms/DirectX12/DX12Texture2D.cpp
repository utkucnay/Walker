#include <Platforms/DirectX12/DX12Texture2D.h>

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
}
