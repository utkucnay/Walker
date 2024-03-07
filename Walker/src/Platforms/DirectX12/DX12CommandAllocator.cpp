#include <Platforms/DirectX12/Command/DX12CommandAllocator.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  DX12CommandAllocator::DX12CommandAllocator(CommandAllocatorBuilder* cab)
  {
    ID3D12Device* nDevice = (ID3D12Device*)Renderer::GetDefaultDevice()->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandAllocator(
        static_cast<D3D12_COMMAND_LIST_TYPE>(cab->m_listType),
        IID_PPV_ARGS(&m_commandAllocator));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Allocator")
    WKR_CORE_LOG("Created DX12 Command Allocator")
  }

  DX12CommandAllocator::~DX12CommandAllocator()
  {
    m_commandAllocator->Release();
  }

  void DX12CommandAllocator::Reset()
  {
    m_commandAllocator->Reset();
  }
}
