#pragma once

#include <Render/Command.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandQueue : public CommandQueue
  {
  public:
    DX12CommandQueue(
        mem::Visitor<Device> device,
        const CommandQueueDesc& desc);
    ~DX12CommandQueue() override;

  public:
    void* GetNativeHandle() override { return commandQueue; }

  private:
    ID3D12CommandQueue* commandQueue;
  };
}
