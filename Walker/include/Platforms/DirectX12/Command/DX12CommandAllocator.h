#pragma once

#include "Graphics/RHI/Command/ICommandAllocator.h"

namespace wkr::graphics::rhi::dx12 {

class UCommandAllocator : public ICommandAllocator {
 public:
  explicit UCommandAllocator(const FCommandAllocatorDesc& desc);

  UCommandAllocator(ID3D12CommandAllocator* commandAlloc)
      : m_CommandAllocator(commandAlloc) {}

  ~UCommandAllocator() override;

 public:
  NativeObject GetNativeObject() override final { return m_CommandAllocator; }

  void Reset() override final;

 private:
  ID3D12CommandAllocator* m_CommandAllocator;
};

}  // namespace wkr::graphics::rhi::dx12
