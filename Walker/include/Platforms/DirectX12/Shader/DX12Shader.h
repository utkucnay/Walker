#pragma once

#include <Render/Shader/Shader.h>

namespace wkr::render::dx12
{
  class UShader : public IShader
  {
  public:
    UShader(FShaderDesc& desc);
    ~UShader() override = default;

  public:
    const std::string& GetCompiledCode() const override { return m_code; }

  private:
    std::string m_code;
  };
}
