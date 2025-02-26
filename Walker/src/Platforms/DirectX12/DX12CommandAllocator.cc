#include "Platforms/DirectX12/Command/DX12CommandAllocator.h"
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UCommandAllocator::UCommandAllocator(const FCommandAllocatorDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  HRESULT hr = nDevice->CreateCommandAllocator(
      wkrtodx12::ConvertECommandType(desc.CommandType),
      IID_PPV_ARGS(&m_CommandAllocator));

  if (FAILED(hr)) {
    WKR_CORE_WARNING("Didn't Create DX12 Command Allocator");
    WKR_DX12_ERROR(hr);
  }

  WKR_CORE_LOG("Created DX12 Command Allocator");
}

UCommandAllocator::~UCommandAllocator() {
  m_CommandAllocator->Release();
}

void UCommandAllocator::Reset() {
  HRESULT hr = m_CommandAllocator->Reset();

  if (FAILED(hr)) {
    WKR_CORE_WARNING("DX12 Command Allocator Not Reset");
    WKR_DX12_ERROR(hr);
  }
}

}  // namespace wkr::graphics::rhi::dx12
