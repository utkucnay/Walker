#include <Platforms/DirectX12/Core/DX12TypeMap.h>
#include <Platforms/DirectX12/Command/DX12CommandAllocator.h>
#include <Render/Core/Renderer.h>

namespace wkr::render::dx12
{
  UCommandAllocator::UCommandAllocator(FCommandAllocatorDesc& desc)
  {
    ID3D12Device* nDevice = URenderer::GetDefaultDevice().GetNativeObject();

    HRESULT hr = nDevice->CreateCommandAllocator(
        ConvertECommandType(desc.commandType),
        IID_PPV_ARGS(&m_commandAllocator));

    m_listType = desc.commandType;

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Allocator");
    WKR_CORE_LOG("Created DX12 Command Allocator");
  }

  UCommandAllocator::~UCommandAllocator()
  {
    m_commandAllocator->Release();
  }

  ECommandType UCommandAllocator::GetCommandType()
  {
    return m_listType;
  }

  void UCommandAllocator::Reset()
  {
    m_commandAllocator->Reset();
  }
}
