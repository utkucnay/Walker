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
    virtual uint64_t GetSize() override;
    virtual Heap::Type GetType() override;
    virtual Heap::CPUPageProperty GetCPUPageProperty() override;
    virtual Heap::MemoryPool GetMemoryPool() override;
    virtual uint64_t GetAlignment() override;
    virtual Heap::Flag GetFlag() override;

  private:
    ID3D12Heap* m_heap;
  };
}
