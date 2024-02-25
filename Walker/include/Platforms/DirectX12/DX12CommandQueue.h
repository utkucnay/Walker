#pragma once

#include <Render/Command.h>

namespace wkr::render
{
  class DX12CommandQueue : public CommandQueue
  {
  public:
    DX12CommandQueue(mem::Ref<Device> device, const CommandQueueDesc& desc);
    ~DX12CommandQueue() override;

  public:
    void* GetNativeHandle() override { return commandQueue; }

  private:
    ID3D12CommandQueue* commandQueue;
  };
}
