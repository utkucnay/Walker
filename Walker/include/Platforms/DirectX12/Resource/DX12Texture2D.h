#pragma once

#include <Render/Resource/Texture2D.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UTexture2D : public ITexture2D
  {
  public:
    UTexture2D(FTexture2DDesc& desc);
    UTexture2D(ID3D12Resource* resource) : m_resource(resource) {}
    ~UTexture2D() override;

  public:
    EResourceState GetState() override final;

    u64    GetWidth()    override final;
    u64    GetHeight()   override final;
    FSample  GetMSAA()     override final;

    NativeObject GetNativeObject() override final { return m_resource; }

  private:
    ID3D12Resource* m_resource;
  };
}
