#pragma once

#include <Render/Resource/Buffers.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class DX12Buffers : public Buffers
  {
  public:
    DX12Buffers(ResourceBuilder<Buffers>* rb);
    ~DX12Buffers() override;

  public:
    virtual void* GetNativeHandle() override { return m_resource; }
    virtual Resource::State GetState() override { return Resource::State::Common; };
    virtual uint64_t GetSize() override { return 0; };

  private:
    ID3D12Resource* m_resource;
  };
}
