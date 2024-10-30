#pragma once

namespace wkr::graphics::rhi
{
  enum class EShaderType
  {
    kVertex,
    kPixel,
  };

  struct FShaderMakro
  {
    std::string Name = {};
    std::string Defination = {};
  };
}
