#pragma once

#include <Render/Resource/Heap.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::rsc
{
  class DX12Heap : public Heap
  {
  public:
    DX12Heap(HeapBuilder* hb);
    ~DX12Heap() override;

  public:
    void* GetNativeHandle() override { return m_heap; };

    uint64_t GetSize() override;
    Heap::Type GetType() override;
    Heap::CPUPageProperty GetCPUPageProperty() override;
    Heap::MemoryPool GetMemoryPool() override;
    uint64_t GetAlignment() override;
    Heap::Flag GetFlag() override;

  private:
    ID3D12Heap* m_heap;
  };
}
