#pragma once

#include "Graphics/Command/ICommandQueue.h"

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
