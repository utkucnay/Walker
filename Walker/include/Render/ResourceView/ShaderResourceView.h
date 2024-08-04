#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class AShaderResourceView : public AResourceView
  {
  public:
    virtual ~AShaderResourceView() override {}

  public:
    std::string GetTypeName() override final { return "ShaderResourceView"; }

  public:
    static std::string GetStaticTypeName() { return "ShaderResourceView"; }
  };
}
