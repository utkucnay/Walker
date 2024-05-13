#pragma once

#include <Render/Resource/Buffers.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class UDX12Buffers : public IBuffers
  {
  public:
    UDX12Buffers(ResourceBuilder<IBuffers>& rb);
    ~UDX12Buffers() override;

  public:
    virtual NativeHandle GetNativeHandle() override { return m_resource; }
    virtual IResource::State GetState() override { return IResource::State::Common; };
    virtual u64 GetSize() override { return 0; };

  private:
    ID3D12Resource* m_resource;
  };
}
