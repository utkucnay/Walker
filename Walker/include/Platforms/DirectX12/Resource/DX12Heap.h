#pragma once

#include <Render/Resource/Heap.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UHeap : public IHeap
  {
  public:
    UHeap(FHeapDesc& desc);
    ~UHeap() override;

  public:
    NativeObject GetNativeObject() override { return m_heap; };

    u64 GetSize() override;
    u64 GetAlignment() override;
    EHeapType GetType() override;
    EHeapFlag GetFlag() override;
    EMemoryPool GetMemoryPool() override;
    ECPUPageProperty GetCPUPageProperty() override;

  private:
    ID3D12Heap* m_heap;
  };
}
