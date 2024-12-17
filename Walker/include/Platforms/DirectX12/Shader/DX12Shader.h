#pragma once

#include "Graphics/RHI/Shader/IShader.h"

namespace wkr::graphics::rhi::dx12 {

class UShader : public IShader {
 public:
  UShader(FShaderDesc& desc);
  ~UShader() override = default;

 public:
  std::string_view GetCompiledCode() const override { return m_code.data(); }

 private:
  std::string m_code;
};

}  // namespace wkr::graphics::rhi::dx12
