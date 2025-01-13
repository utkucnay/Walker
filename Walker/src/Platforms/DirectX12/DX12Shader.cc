#include "Platforms/DirectX12/Shader/DX12Shader.h"

namespace wkr::graphics::rhi::dx12 {

static std::unordered_map<EShaderType, std::string> vsMap = {
  {EShaderType::kVertex, "vs_5_0"},
  {EShaderType::kPixel, "ps_5_0"},
};

UShader::UShader(const FShaderDesc& desc) {
  ID3DBlob* code;
  ID3DBlob* error;

  HRESULT hr =
      D3DCompile(desc.sourceCode.data(), desc.sourceCode.size(),
                 desc.name.data(), nullptr, nullptr, desc.entryPoint.data(),
                 vsMap[desc.type].c_str(), 0, 0, &code, &error);

  if (FAILED(hr)) {
    std::string errorString(static_cast<char*>(error->GetBufferPointer()),
                            error->GetBufferSize());
    WKR_CORE_ERROR("DX12 Shader Not Created\n" + errorString);
  }

  m_code = std::string((char*)code->GetBufferPointer(), code->GetBufferSize());
  WKR_CORE_LOG("Created DX12 Shader!")
}

}  // namespace wkr::render::dx12
