#include <Render/Core/Renderer.h>
#include <Render/Descriptor/DescriptorHeap.h>
#include <Platforms/DirectX12/Descriptor/DX12DescriptorHeap.h>

namespace wkr::render
{
  UDX12DescriptorHeap::UDX12DescriptorHeap(DescriptorHeapBuilder& dhb)
  {
    ID3D12Device* nDevice = static_cast<ID3D12Device*>(URenderer::GetDefaultDevice()
        .GetNativeHandle());

    D3D12_DESCRIPTOR_HEAP_DESC nDHeapDesc{};
    nDHeapDesc.NumDescriptors = dhb.m_count;
    nDHeapDesc.Type   = static_cast<D3D12_DESCRIPTOR_HEAP_TYPE>(dhb.m_type);
    nDHeapDesc.Flags  = static_cast<D3D12_DESCRIPTOR_HEAP_FLAGS>(dhb.m_flags);

    HRESULT hr = nDevice->CreateDescriptorHeap(&nDHeapDesc,
        IID_PPV_ARGS(&m_descriptorHeap));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create Descriptor Heap")
    WKR_CORE_LOG("Created Descriptor Heap")
  }

  UDX12DescriptorHeap::~UDX12DescriptorHeap()
  {
    m_descriptorHeap->Release();
  }

  u32 UDX12DescriptorHeap::GetCount()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return desc.NumDescriptors;
  }

  IDescriptorHeap::Type UDX12DescriptorHeap::GetType()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return static_cast<IDescriptorHeap::Type>(desc.Type);
  }

  IDescriptorHeap::Flags UDX12DescriptorHeap::GetFlags()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return static_cast<IDescriptorHeap::Flags>(desc.Flags);
  }

  void UDX12DescriptorHeap::Bind(
      const std::vector<mem::WeakRef<rsc::IResource>>& resources)
  {
    auto nDevice = static_cast<ID3D12Device*>(URenderer::GetDefaultDevice()
        .GetNativeHandle());
    auto rtvSize = nDevice->
      GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
        m_descriptorHeap->GetCPUDescriptorHandleForHeapStart());

    for(int i = 0; i < resources.size(); i++)
    {
      auto resource = static_cast<ID3D12Resource*>(
          resources[i].Lock()->GetNativeHandle());

      nDevice->CreateRenderTargetView(resource, NULL, rtvHandle);
      WKR_CORE_LOG("Binding Render Texture on Descriptor Heap")
        switch (GetType())
        {
          case IDescriptorHeap::Type::RTV:
            {
              m_resourceViews.push_back(mem::Ref<view::UDX12RenderTargetView>
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
