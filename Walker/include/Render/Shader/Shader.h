#pragma once

#include <Render/Shader/ShaderType.h>

namespace wkr::render
{
  struct FShaderDesc
  {
    EShaderType type;
    std::string name;
    std::string sourceCode;
    std::string entryPoint;
    FShaderMakro* shaderMakro;
  };

  class IShader
  {
  public:
    virtual ~IShader() = default;

  public:
    virtual const std::string& GetCompiledCode() const = 0;
  };

  using IShaderHandle = mem::TRef<IShader>;
}
