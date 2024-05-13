#pragma once

#include <Render/Resource/Texture2D.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class UDX12Texture2D : public ITexture2D
  {
  public:
    UDX12Texture2D() {}
    UDX12Texture2D(ID3D12Resource* resource) : m_resource(resource) {}
    ~UDX12Texture2D() override;

  public:
    IResource::State GetState() override final;

    u64    GetWidth()    override final;
    u64    GetHeight()   override final;
    FSample  GetMSAA()     override final;

    NativeHandle GetNativeHandle() override final { return m_resource; }

  private:
    ID3D12Resource* m_resource;
  };
}
