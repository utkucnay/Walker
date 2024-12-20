#include "Platforms/DirectX12/Resource/DX12Heap.h"
#include "Graphics/Core/UGraphics.h"
#include "Graphics/RHI/Memory/IHeap.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UHeap::UHeap(FHeapDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  D3D12_HEAP_DESC nDesc = {
      .SizeInBytes = desc.Size,
      .Properties = wkrtodx12::ConvertFHeapProperty(desc.HeapProperties),
      .Alignment = desc.Alignment,
      .Flags = wkrtodx12::ConvertEHeapF(desc.Flag),
  };

  HRESULT hr = nDevice->CreateHeap(&nDesc, IID_PPV_ARGS(&m_heap));

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create Heap");
  WKR_CORE_LOG("Created Heap");
}

UHeap::~UHeap() {
  m_heap->Release();
}

FHeapDesc UHeap::GetDesc() {
  D3D12_HEAP_DESC desc = m_heap->GetDesc();

  FHeapDesc retDesc = {
    .Size = desc.SizeInBytes,
    .Alignment = desc.Alignment,
    .HeapProperties = dx12towkr::ConvertFHeapProperty(desc.Properties),
    .Flag = dx12towkr::ConvertEHeapF(desc.Flags),
  };

  return retDesc;
}

}  // namespace wkr::graphics::rhi::dx12
