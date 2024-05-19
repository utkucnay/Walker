#include <Platforms/DirectX12/Core/DX12RootSignature.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  UDX12RootSignature::UDX12RootSignature(
      RootSignatureBuilder& rootSignatureBuilder)
  {
    auto nDevice = static_cast<ID3D12Device*>(
        URenderer::GetDefaultDevice().GetNativeHandle());

    HRESULT hr;

    CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
    rootSignatureDesc.Init(
        0,
        nullptr,
        0,
        nullptr,
        D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ID3DBlob* signature;
    hr = D3D12SerializeRootSignature(
        &rootSignatureDesc,
        D3D_ROOT_SIGNATURE_VERSION_1,
        &signature,
        nullptr);
    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Created Serialize RS!");

    hr = nDevice->CreateRootSignature(
        0,
        signature->GetBufferPointer(),
        signature->GetBufferSize(),
        IID_PPV_ARGS(&m_rootSignature));
    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Created RS!");

    WKR_CORE_LOG("Created DX12 Root Signature");
  }

  UDX12RootSignature::~UDX12RootSignature()
  {
    m_rootSignature->Release();
  }
}
