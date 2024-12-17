#pragma once

#include "Graphics/RHI/Command/ICommandAllocator.h"

namespace wkr::graphics::rhi::dx12 {

class UCommandAllocator : public ICommandAllocator {
 public:
  UCommandAllocator(FCommandAllocatorDesc& desc);
  ~UCommandAllocator() override;

 public:
  NativeObject GetNativeObject() override final { return m_commandAllocator; }

  FCommandAllocatorDesc GetDesc() const override final;
  void Reset() override final;

 private:
  ID3D12CommandAllocator* m_commandAllocator;
  ECommandType m_CommandType;
};

}  // namespace wkr::graphics::rhi::dx12
