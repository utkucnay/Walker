#include <Platforms/DirectX12/Command/DX12CommandAllocator.h>
#include <Render/Core/Renderer.h>

namespace wkr::render::dx12
{
  UCommandAllocator::UCommandAllocator(FCommandAllocatorDesc& desc)
  {
    ID3D12Device* nDevice = (ID3D12Device*)URenderer::GetDefaultDevice()
      .GetNativeHandle();
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
