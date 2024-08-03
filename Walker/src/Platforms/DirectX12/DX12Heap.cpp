#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Heap.h>

namespace wkr::render::dx12
{
  UHeap::UHeap(FHeapDesc& desc)
  {
    auto nDevice = static_cast<ID3D12Device*>(
        URenderer::GetDefaultDevice().GetNativeHandle());
  }

  UHeap::~UHeap()
  {
    m_heap->Release();
  }

  u64 UHeap::GetSize()
  {
    auto desc = m_heap->GetDesc();
    return desc.SizeInBytes;
  }

  EHeapType UHeap::GetType()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<EHeapType>(desc.Properties.Type);
  }

  ECPUPageProperty UHeap::GetCPUPageProperty()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<ECPUPageProperty>(desc.Properties.CPUPageProperty);
  }

  EMemoryPool UHeap::GetMemoryPool()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<EMemoryPool>(desc.Properties.MemoryPoolPreference);
  }

  u64 UHeap::GetAlignment()
  {
    auto desc = m_heap->GetDesc();
    return desc.Alignment;
  }

  EHeapFlag UHeap::GetFlag()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<EHeapFlag>(desc.Flags);
  }
}
