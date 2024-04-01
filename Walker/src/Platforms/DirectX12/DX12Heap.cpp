#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Heap.h>

namespace wkr::render::rsc
{
  DX12Heap::DX12Heap(HeapBuilder* hb)
  {
    auto nDevice = static_cast<ID3D12Device*>(
        Renderer::GetDefaultDevice()->GetNativeHandle());

    D3D12_HEAP_DESC desc{};
    desc.SizeInBytes = hb->m_size;

    desc.Properties.Type = static_cast<D3D12_HEAP_TYPE>(hb->m_type);
    desc.Properties.CPUPageProperty = static_cast<D3D12_CPU_PAGE_PROPERTY>(
        hb->m_cpuPageProperty);
    desc.Properties.MemoryPoolPreference = static_cast<D3D12_MEMORY_POOL>(
        hb->m_memoryPool);

    desc.Alignment = hb->m_alignment;
    desc.Flags = static_cast<D3D12_HEAP_FLAGS>(hb->m_flag);

    nDevice->CreateHeap(
        &desc,
        IID_PPV_ARGS(&m_heap));
  }

  DX12Heap::~DX12Heap()
  {
    m_heap->Release();
  }

  uint64_t DX12Heap::GetSize()
  {
    auto desc = m_heap->GetDesc();
    return desc.SizeInBytes;
  }

  Heap::Type DX12Heap::GetType()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<Heap::Type>(desc.Properties.Type);
  }

  Heap::CPUPageProperty DX12Heap::GetCPUPageProperty()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<Heap::CPUPageProperty>(desc.Properties.CPUPageProperty);
  }

  Heap::MemoryPool DX12Heap::GetMemoryPool()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<Heap::MemoryPool>(desc.Properties.MemoryPoolPreference);
  }

  uint64_t DX12Heap::GetAlignment()
  {
    auto desc = m_heap->GetDesc();
    return desc.Alignment;
  }

  Heap::Flag DX12Heap::GetFlag()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<Heap::Flag>(desc.Flags);
  }
}
