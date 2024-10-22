#pragma once

#include "Graphics/Core/IRootSignature.h"

namespace wkr::render::dx12
{
  class URootSignature : public IRootSignature
  {
  public:
    URootSignature(FRootSignatureDesc& desc);
    ~URootSignature() override;

  public:
    NativeObject GetNativeObject() override final { return m_rootSignature; }

  private:
    ID3D12RootSignature* m_rootSignature;
  };
}
