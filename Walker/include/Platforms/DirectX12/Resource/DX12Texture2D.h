#pragma once

#include <Render/Resource/Texture2D.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class DX12Texture2D : public Texture2D
  {
  public:
    DX12Texture2D() {}
    DX12Texture2D(ID3D12Resource* resource) : m_resource(resource) {}
    ~DX12Texture2D() override;

  public:
    Resource::State GetState() override final;

    uint64_t    GetWidth()    override final;
    uint64_t    GetHeight()   override final;
    SampleDesc  GetMSAA()     override final;

    void* GetNativeHandle() override final { return m_resource; }

  private:
    ID3D12Resource* m_resource;
  };
}
