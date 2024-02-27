#include <Platforms/DirectX12/DX12CommandAllocator.h>

namespace wkr::render
{
  DX12CommandAllocator::DX12CommandAllocator(
      Device* device,
      CommandList::Type listType)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandAllocator(
        static_cast<D3D12_COMMAND_LIST_TYPE>(listType),
        IID_PPV_ARGS(&commandAllocator));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command Allocator");
  }

  DX12CommandAllocator::~DX12CommandAllocator()
  {
    commandAllocator->Release();
  }
}
