#pragma once

#include "Graphics/RHI/Shader/ShaderType.h"

namespace wkr::graphics::rhi {

struct FShaderDesc {
  EShaderType type = EShaderType::kVertex;
  std::string_view name = {};
  std::string_view sourceCode = {};
  std::string_view entryPoint = {};
  wkr::mem::TScope<FShaderMakro> shaderMakro = {};
};

class IShader {
 public:
  virtual ~IShader() = default;

 public:
  virtual std::string_view GetCompiledCode() const = 0;
};

using IShaderHandle = mem::TRef<IShader>;

}  // namespace wkr::graphics::rhi
