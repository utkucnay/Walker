#pragma once

#include <Render/Resource/Buffers.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UBuffers : public IBuffers
  {
  public:
    UBuffers(FBuffersDesc& desc);
    ~UBuffers() override;

  public:
    virtual NativeObject GetNativeObject() override { return m_resource; }
    virtual EResourceState GetState() override { return EResourceState::Common; };
    virtual u64 GetSize() override { return 0; };

  private:
    ID3D12Resource* m_resource;
  };
}
