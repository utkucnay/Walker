#pragma once

#include <Render/Command/CommandQueue.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UCommandQueue : public ICommandQueue
  {
  public:
    UCommandQueue(FCommandQueueDesc& desc);
    ~UCommandQueue() override;

  public:
    NativeObject GetNativeObject() override { return m_commandQueue; }

    void ExecuteCommandList(
        const std::vector<ICommandList*>& commandLists) override final;

    void Signal(IFence& fence, i32 frameIndex) override final;

  private:
    ID3D12CommandQueue* m_commandQueue;
  };
}
