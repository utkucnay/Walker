#pragma once

#include <Render/Shader/Shader.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  class IVertexShader : public IShader
  {
  public:
    virtual ~IVertexShader() {}

  };

  class VertexShaderBuilder : IBuilder<IVertexShader>
  {
    //REGISTER_BUILDER(I, VertexShader);
  };
}
