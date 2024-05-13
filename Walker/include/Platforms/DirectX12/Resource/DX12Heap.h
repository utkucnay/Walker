#pragma once

#include <Render/Resource/Heap.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class UDX12Heap : public IHeap
  {
  public:
    UDX12Heap(HeapBuilder& hb);
    ~UDX12Heap() override;

  public:
    NativeHandle GetNativeHandle() override { return m_heap; };

    u64 GetSize() override;
    u64 GetAlignment() override;
    IHeap::Type GetType() override;
    IHeap::Flag GetFlag() override;
    IHeap::MemoryPool GetMemoryPool() override;
    IHeap::CPUPageProperty GetCPUPageProperty() override;

  private:
    ID3D12Heap* m_heap;
  };
}
