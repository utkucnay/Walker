#include <Platforms/DirectX12/Command/DX12CommandAllocator.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  UDX12CommandAllocator::UDX12CommandAllocator(CommandAllocatorBuilder& cab)
  {
    ID3D12Device* nDevice = (ID3D12Device*)URenderer::GetDefaultDevice()
      .GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandAllocator(
        static_cast<D3D12_COMMAND_LIST_TYPE>(cab.m_listType),
        IID_PPV_ARGS(&m_commandAllocator));

    m_listType = cab.m_listType;

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Allocator")
    WKR_CORE_LOG("Created DX12 Command Allocator")
  }

  UDX12CommandAllocator::~UDX12CommandAllocator()
  {
    m_commandAllocator->Release();
  }

  ICommandList::Type UDX12CommandAllocator::GetCommandListType()
  {
    return m_listType;
  }

  void UDX12CommandAllocator::Reset()
  {
    m_commandAllocator->Reset();
  }

  void UDX12CommandAllocator::Clone(
      ICommandAllocator& commandAllocator)
  {
    auto nDevice = static_cast<ID3D12Device*>(URenderer::GetDefaultDevice().GetNativeHandle());
    auto dx12CommandAllocator = static_cast<UDX12CommandAllocator&>(commandAllocator);

    nDevice->CreateCommandAllocator(
          static_cast<D3D12_COMMAND_LIST_TYPE>(this->m_listType),
          IID_PPV_ARGS(&dx12CommandAllocator.m_commandAllocator));
  }
}
