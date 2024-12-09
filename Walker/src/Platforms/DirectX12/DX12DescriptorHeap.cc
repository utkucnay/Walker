#include "Platforms/DirectX12/Descriptor/DX12DescriptorHeap.h"
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UDescriptorHeap::UDescriptorHeap(FDescriptorHeapDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  D3D12_DESCRIPTOR_HEAP_DESC nDHeapDesc{
    .Type = ConvertEDescriptorHeapType(desc.Type),
    .NumDescriptors = desc.Count,
    .Flags = ConvertEDescriptorHeapF(desc.Flag),
  };

  HRESULT hr = nDevice->CreateDescriptorHeap(&nDHeapDesc,
                                             IID_PPV_ARGS(&m_descriptorHeap));

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create Descriptor Heap")
  WKR_CORE_LOG("Created DX12 Descriptor Heap")
}

UDescriptorHeap::~UDescriptorHeap() {
  m_descriptorHeap->Release();
}

u32 UDescriptorHeap::GetCount() {
  D3D12_DESCRIPTOR_HEAP_DESC desc;

  desc = m_descriptorHeap->GetDesc();
  return desc.NumDescriptors;
}

EDescriptorHeapType UDescriptorHeap::GetType() {
  D3D12_DESCRIPTOR_HEAP_DESC desc;

  desc = m_descriptorHeap->GetDesc();
  return static_cast<EDescriptorHeapType>(desc.Type);
}

EDescriptorHeapFlags UDescriptorHeap::GetFlags() {
  D3D12_DESCRIPTOR_HEAP_DESC desc;

  desc = m_descriptorHeap->GetDesc();
  return static_cast<EDescriptorHeapFlags>(desc.Flags);
}

void UDescriptorHeap::Bind(const std::vector<IResourceHandle>& resources) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  auto rtvSize =
      nDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

  CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
      m_descriptorHeap->GetCPUDescriptorHandleForHeapStart());

  for (int i = 0; i < resources.size(); i++) {
    ID3D12Resource* resource = resources[i]->GetNativeObject();

    nDevice->CreateRenderTargetView(resource, nullptr, rtvHandle);
    WKR_CORE_LOG("Binding Render Texture on Descriptor Heap")
    switch (GetType()) {
      case EDescriptorHeapType::RTV: {
        m_resourceViews.push_back(mem::TRef<dx12::URenderTargetView>::Create(
            rtvHandle, new UTexture2D(resources[i])));
      } break;

      default: {
        WKR_CORE_WARNING("Not Implemented Heap Type");
      } break;
    }
    rtvHandle.Offset(1, rtvSize);
  }
}

}  // namespace wkr::render::dx12
