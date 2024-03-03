#include <Platforms/DirectX12/DX12CommandAllocator.h>

namespace wkr::render
{
  DX12CommandAllocator::DX12CommandAllocator(
      mem::Visitor<Device>                  device,
      mem::Visitor<CommandAllocatorBuilder> cab)
    : CommandAllocator(cab)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandAllocator(
        static_cast<D3D12_COMMAND_LIST_TYPE>(m_listType),
        IID_PPV_ARGS(&commandAllocator));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Allocator")
    WKR_CORE_LOG("Created DX12 Command Allocator")
  }

  DX12CommandAllocator::~DX12CommandAllocator()
  {
    commandAllocator->Release();
  }
}
