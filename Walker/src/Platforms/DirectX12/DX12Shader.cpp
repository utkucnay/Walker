#include "Core/Base.h"
#include <Platforms/DirectX12/Shader/DX12Shader.h>

namespace wkr::render::dx12
{
  UShader::UShader(FShaderDesc& desc)
  {
    static std::unordered_map<EShaderType, std::string> vsMap =
    {
      { EShaderType::Vertex, "vs_5_0" },
      { EShaderType::Pixel, "ps_5_0" },
    };

    ID3DBlob* code;
    ID3DBlob* error;

    HRESULT hr = D3DCompile(
        desc.sourceCode.c_str(),
        desc.sourceCode.size(),
        desc.name.c_str(),
        nullptr,
        nullptr,
        desc.entryPoint.c_str(),
        vsMap[desc.type].c_str(),
        0,
        0,
        &code,
        &error);


    if(FAILED(hr))
    {
      std::string errorString((char*)error->GetBufferPointer(), error->GetBufferSize());
      WKR_CORE_ERROR("DX12 Shader Not Created\n" + errorString);
    }

    m_code = std::string((char*)code->GetBufferPointer(), code->GetBufferSize());
    WKR_CORE_LOG("Created DX12 Shader!")
  }
}
