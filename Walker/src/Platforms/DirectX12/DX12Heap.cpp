#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Heap.h>

namespace wkr::render::rsc
{
  UDX12Heap::UDX12Heap(HeapBuilder& hb)
  {
    auto nDevice = static_cast<ID3D12Device*>(
        URenderer::GetDefaultDevice().GetNativeHandle());

    D3D12_HEAP_DESC desc{};
    desc.SizeInBytes = hb.m_size;

    desc.Properties.Type = static_cast<D3D12_HEAP_TYPE>(hb.m_type);
    desc.Properties.CPUPageProperty = static_cast<D3D12_CPU_PAGE_PROPERTY>(
        hb.m_cpuPageProperty);
    desc.Properties.MemoryPoolPreference = static_cast<D3D12_MEMORY_POOL>(
        hb.m_memoryPool);

    desc.Alignment = hb.m_alignment;
    desc.Flags = static_cast<D3D12_HEAP_FLAGS>(hb.m_flag);

    nDevice->CreateHeap(
        &desc,
        IID_PPV_ARGS(&m_heap));
  }

  UDX12Heap::~UDX12Heap()
  {
    m_heap->Release();
  }

  u64 UDX12Heap::GetSize()
  {
    auto desc = m_heap->GetDesc();
    return desc.SizeInBytes;
  }

  IHeap::Type UDX12Heap::GetType()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<IHeap::Type>(desc.Properties.Type);
  }

  IHeap::CPUPageProperty UDX12Heap::GetCPUPageProperty()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<IHeap::CPUPageProperty>(desc.Properties.CPUPageProperty);
  }

  IHeap::MemoryPool UDX12Heap::GetMemoryPool()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<IHeap::MemoryPool>(desc.Properties.MemoryPoolPreference);
  }

  u64 UDX12Heap::GetAlignment()
  {
    auto desc = m_heap->GetDesc();
    return desc.Alignment;
  }

  IHeap::Flag UDX12Heap::GetFlag()
  {
    auto desc = m_heap->GetDesc();
    return static_cast<IHeap::Flag>(desc.Flags);
  }
}
