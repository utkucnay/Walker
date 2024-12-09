#pragma once

#include "Graphics/RHI/Memory/IHeap.h"

namespace wkr::graphics::rhi::dx12 {

class UHeap : public IHeap {
 public:
  UHeap(FHeapDesc& desc);
  ~UHeap() override;

 public:
  NativeObject GetNativeObject() override final { return m_heap; };
  FHeapDesc GetDesc() override final;

 private:
  ID3D12Heap* m_heap;
};

}  // namespace wkr::graphics::rhi::dx12
