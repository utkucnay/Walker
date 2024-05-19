#pragma once

#include <Render/Core/RootSignature.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12RootSignature : public IRootSignature
  {
  public:
    UDX12RootSignature(RootSignatureBuilder& rootSignatureBuilder);
    ~UDX12RootSignature() override;

  public:
    NativeHandle GetNativeHandle() override final { return m_rootSignature; }

  private:
    ID3D12RootSignature* m_rootSignature;
  };
}
