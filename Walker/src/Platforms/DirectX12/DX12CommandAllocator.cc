#include "Platforms/DirectX12/Command/DX12CommandAllocator.h"
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UCommandAllocator::UCommandAllocator(FCommandAllocatorDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  HRESULT hr = nDevice->CreateCommandAllocator(
      wkrtodx12::ConvertECommandType(desc.CommandType),
      IID_PPV_ARGS(&m_commandAllocator));

  m_CommandType = desc.CommandType;

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Allocator");
  WKR_CORE_LOG("Created DX12 Command Allocator");
}

UCommandAllocator::~UCommandAllocator() {
  m_commandAllocator->Release();
}

FCommandAllocatorDesc UCommandAllocator::GetDesc() const {
  FCommandAllocatorDesc desc = {
      .CommandType = m_CommandType,
  };
  return desc;
}

void UCommandAllocator::Reset() {
  m_commandAllocator->Reset();
}

}  // namespace wkr::graphics::rhi::dx12
