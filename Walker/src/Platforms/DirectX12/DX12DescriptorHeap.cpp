#include <Render/Core/Renderer.h>
#include <Render/Descriptor/DescriptorHeap.h>
#include <Platforms/DirectX12/Descriptor/DX12DescriptorHeap.h>

namespace wkr::render::dx12
{
  UDescriptorHeap::UDescriptorHeap(FDescriptorHeapDesc& desc)
  {
    ID3D12Device* nDevice = static_cast<ID3D12Device*>(URenderer::GetDefaultDevice()
        .GetNativeHandle());
  }

  UDescriptorHeap::~UDescriptorHeap()
  {
    m_descriptorHeap->Release();
  }

  u32 UDescriptorHeap::GetCount()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return desc.NumDescriptors;
  }

  EDescriptorHeapType UDescriptorHeap::GetType()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return static_cast<EDescriptorHeapType>(desc.Type);
  }

  EDescriptorHeapFlags UDescriptorHeap::GetFlags()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return static_cast<EDescriptorHeapFlags>(desc.Flags);
  }

  void UDescriptorHeap::Bind(
      const std::vector<IResourceHandle>& resources)
  {
    auto nDevice = static_cast<ID3D12Device*>(URenderer::GetDefaultDevice()
        .GetNativeHandle());
    auto rtvSize = nDevice->
      GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    CD3_CPU_DESCRIPTOR_HANDLE rtvHandle(
        m_descriptorHeap->GetCPUDescriptorHandleForHeapStart());

    for(int i = 0; i < resources.size(); i++)
    {
      auto resource = static_cast<ID3D12Resource*>(
          resources[i]->GetNativeHandle());

      nDevice->CreateRenderTargetView(resource, NULL, rtvHandle);
      WKR_CORE_LOG("Binding Render Texture on Descriptor Heap")
        switch (GetType())
        {
          case EDescriptorHeapType::RTV:
            {
              m_resourceViews.push_back(URenderTargetViewHandle
                  ::Create(rtvHandle, resources[i]));
            } break;

          default:
            {
              WKR_CORE_WARNING("Not Implemented Heap Type");
            } break;
        }
      rtvHandle.Offset(1, rtvSize);
    }
  }
}
