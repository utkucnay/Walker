#pragma once

#include <Render/Resource/Buffers.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class DX12Buffers : public Buffers
  {
  public:
    DX12Buffers(ResourceBuilder<Buffers>* rb);

  public:
    virtual void* GetNativeHandle() { return m_resource; }
    virtual Resource::State GetState() { return Resource::State::Common; };
    virtual uint64_t GetSize() { return 0; };

  private:
    ID3D12Resource* m_resource;
  };
}
