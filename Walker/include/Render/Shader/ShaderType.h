#pragma once

namespace wkr::render
{
  enum class EShaderType
  {
    Vertex,
    Pixel,
  };

  struct FShaderMakro
  {
    std::string name;
    std::string defination;
  };
}
