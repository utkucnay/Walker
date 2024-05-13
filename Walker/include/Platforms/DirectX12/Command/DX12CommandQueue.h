#pragma once

#include <Render/Command/CommandQueue.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12CommandQueue : public ICommandQueue
  {
  public:
    UDX12CommandQueue(CommandQueueBuilder& cqb);
    ~UDX12CommandQueue() override;

  public:
    NativeHandle GetNativeHandle() override { return m_commandQueue; }

    void ExecuteCommandList(
        const std::vector<mem::Ref<ICommandList>>& commandLists) override final;

    void Signal(IFence& fence, i32 frameIndex) override final;

  private:
    ID3D12CommandQueue* m_commandQueue;
  };
}
