#pragma once

#include <Render/Command/CommandQueue.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandQueue : public CommandQueue
  {
  public:
    DX12CommandQueue(CommandQueueBuilder* cqb);
    ~DX12CommandQueue() override;

  public:
    void* GetNativeHandle() override { return m_commandQueue; }

  private:
    ID3D12CommandQueue* m_commandQueue;
  };
}
