#include "Platforms/DirectX12/Descriptor/DX12DescriptorHeap.h"
#include "Core/Base.h"
#include "Graphics/Core/UGraphics.h"
#include "Graphics/RHI/Descriptor/ADescriptorHeap.h"
#include "Graphics/RHI/Descriptor/DescriptorType.h"
#include "Graphics/RHI/Resource/View/AResourceView.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"
#include "Platforms/DirectX12/ResourceView/DX12ResourceView.h"

namespace wkr::graphics::rhi::dx12 {

UDescriptorHeap::UDescriptorHeap(FDescriptorHeapDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  D3D12_DESCRIPTOR_HEAP_DESC nDHeapDesc{
      .Type = wkrtodx12::ConvertEDescriptorHeapType(desc.Type),
      .NumDescriptors = desc.Count,
      .Flags = wkrtodx12::ConvertEDescriptorHeapF(desc.Flag),
  };

  HRESULT hr = nDevice->CreateDescriptorHeap(&nDHeapDesc,
                                             IID_PPV_ARGS(&m_descriptorHeap));

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create Descriptor Heap")
  WKR_CORE_LOG("Created DX12 Descriptor Heap")
}

UDescriptorHeap::~UDescriptorHeap() {
  m_descriptorHeap->Release();
}

FDescriptorHeapDesc UDescriptorHeap::GetDesc() {
  D3D12_DESCRIPTOR_HEAP_DESC desc = m_descriptorHeap->GetDesc();
  FDescriptorHeapDesc retDesc = {
      .Count = desc.NumDescriptors,
      .Type = dx12towkr::ConvertEDescriptorHeapType(desc.Type),
      .Flag = dx12towkr::ConvertEDescriptorHeapF(desc.Flags),
  };
  return retDesc;
}

void UDescriptorHeap::Bind(const std::vector<IResourceHandle>& resources) {
  FDescriptorHeapDesc desc = GetDesc();

  switch (desc.Type) {
    case EDescriptorHeapType::kRTV: {
      BindRTV(resources);
    } break;

    default: {
      WKR_CORE_ERROR("Descriptor Heap Not Implemented");
    } break;
  }
}

void UDescriptorHeap::BindRTV(const std::vector<IResourceHandle>& resources) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
      m_descriptorHeap->GetCPUDescriptorHandleForHeapStart());

  u32 rtvSize =
      nDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

  for (int i = 0; i < resources.size(); i++) {
    ID3D12Resource* resource = resources[i]->GetNativeObject();

    nDevice->CreateRenderTargetView(resource, nullptr, rtvHandle);
    WKR_CORE_LOG("Binding Render Texture on Descriptor Heap");
    AResourceViewHandle resourceView =
        AResourceViewHandle(new UResourceView(rtvHandle, resources[i]));
    m_ResourceViews.push_back(resourceView);

    rtvHandle.Offset(1, rtvSize);
  }
}

}  // namespace wkr::graphics::rhi::dx12
