#include "Platforms/DirectX12/Core/DX12RootSignature.h"
#include "Graphics/Core/UGraphics.h"

namespace wkr::graphics::rhi::dx12 {

URootSignature::URootSignature(const FRootSignatureDesc& desc) {
  auto nDevice = UGraphics::GetDefaultDevice().GetNativeObject();
}

URootSignature::~URootSignature() {
  m_rootSignature->Release();
}

}  // namespace wkr::render::dx12
