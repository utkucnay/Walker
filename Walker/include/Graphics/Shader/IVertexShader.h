#pragma once

#include "Graphics/Shader/IShader.h"

namespace wkr::render
{
  struct FVertexShaderDesc
  {

  };

  class IVertexShader : public IShader
  {
  public:
    virtual ~IVertexShader() = default;

  };

  using IVertexShaderHandle = mem::TRef<IVertexShader>;
}
