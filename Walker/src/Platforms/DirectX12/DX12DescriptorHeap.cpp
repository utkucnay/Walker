#include "d3d12.h"
#include "d3dx12/d3dx12_root_signature.h"
#include <Platforms/DirectX12/DX12DescriptorHeap.h>

namespace wkr::render
{
  DX12DescriptorHeap::DX12DescriptorHeap(
      mem::Visitor<Device> device,
      mem::Visitor<DescriptorHeapBuilder> dhb)
  {
    ID3D12Device* nDevice = static_cast<ID3D12Device*>(device->GetNativeHandle());

    D3D12_DESCRIPTOR_HEAP_DESC nDHeapDesc{};
    nDHeapDesc.NumDescriptors = dhb->m_count;
    nDHeapDesc.Type   = static_cast<D3D12_DESCRIPTOR_HEAP_TYPE>(dhb->m_type);
    nDHeapDesc.Flags  = static_cast<D3D12_DESCRIPTOR_HEAP_FLAGS>(dhb->m_flags);

    HRESULT hr = nDevice->CreateDescriptorHeap(&nDHeapDesc,
        IID_PPV_ARGS(&m_descriptorHeap));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create Descriptor Heap")
    WKR_CORE_LOG("Created Descriptor Heap")
  }

  DX12DescriptorHeap::~DX12DescriptorHeap()
  {
    m_descriptorHeap->Release();
  }

  uint32_t DX12DescriptorHeap::GetCount()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return desc.NumDescriptors;
  }

  DescriptorHeap::Type DX12DescriptorHeap::GetType()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return static_cast<DescriptorHeap::Type>(desc.Type);
  }

  DescriptorHeap::Flags DX12DescriptorHeap::GetFlags()
  {
    D3D12_DESCRIPTOR_HEAP_DESC desc;

    desc = m_descriptorHeap->GetDesc();
    return static_cast<DescriptorHeap::Flags>(desc.Flags);
  }

  void DX12DescriptorHeap::Bind(
      mem::Visitor<Device> device,
      int count,
      std::vector<mem::Visitor<rsc::Texture2D>> allTexture)
  {
    auto nDevice = static_cast<ID3D12Device*>(device->GetNativeHandle());
    auto rtvSize = nDevice->
      GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
        m_descriptorHeap->GetCPUDescriptorHandleForHeapStart());

    for(int i = 0; i < count; i++)
    {
      auto resource = static_cast<ID3D12Resource*>(
          allTexture[i]->GetNativeHandle());

      nDevice->CreateRenderTargetView(resource, NULL, rtvHandle);
      WKR_CORE_LOG("Binding Render Texture on Descriptor Heap")
      rtvHandle.Offset(1, rtvSize);
    }
  }
}
