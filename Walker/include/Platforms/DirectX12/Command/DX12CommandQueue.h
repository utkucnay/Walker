#pragma once

#include "Graphics/RHI/Command/ICommandQueue.h"

namespace wkr::graphics::rhi::dx12 {

class UCommandQueue : public ICommandQueue {
 public:
  explicit UCommandQueue(const FCommandQueueDesc& desc);
  ~UCommandQueue() override;

 public:
  void ExecuteCommandList(
      const std::vector<ICommandList*>& commandLists) override final;

  NativeObject GetNativeObject() override final { return m_commandQueue; }

  FCommandQueueDesc GetDesc() override final;
  void Signal(AFence& fence, i32 frameIndex) override final;

 private:
  ID3D12CommandQueue* m_commandQueue;
};

}  // namespace wkr::graphics::rhi::dx12
