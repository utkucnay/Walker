#include <Platforms/DirectX12/Core/DX12RootSignature.h>
#include <Render/Core/Renderer.h>

namespace wkr::render::dx12
{
  URootSignature::URootSignature(FRootSignatureDesc& desc)
  {
    auto nDevice = static_cast<ID3D12Device*>(
        URenderer::GetDefaultDevice().GetNativeHandle());
  }

  URootSignature::~URootSignature()
  {
    m_rootSignature->Release();
  }
}
