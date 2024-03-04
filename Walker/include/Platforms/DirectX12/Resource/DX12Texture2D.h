#pragma once

#include <Render/Resource/Texture2D.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class DX12Texture2D : public Texture2D
  {
  public:
    DX12Texture2D(ID3D12Resource* resource) : m_resource(resource) {}

  public:
    void* GetNativeHandle() override final { return m_resource; }
    uint64_t GetWidth() override final;
    uint64_t GetHeight() override final;
    SampleDesc  GetMSAA() override final;

  private:
    ID3D12Resource* m_resource;
  };
}
