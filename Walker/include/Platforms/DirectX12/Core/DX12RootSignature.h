#pragma once

#include "Graphics/RHI/Core/IRootSignature.h"

namespace wkr::graphics::rhi::dx12 {

class URootSignature : public IRootSignature {
 public:
  explicit URootSignature(const FRootSignatureDesc& desc);
  ~URootSignature() override;

 public:
  NativeObject GetNativeObject() override final { return m_rootSignature; }

 private:
  ID3D12RootSignature* m_rootSignature;
};

}  // namespace wkr::graphics::rhi::dx12
