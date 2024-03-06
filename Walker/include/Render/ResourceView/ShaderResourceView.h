#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class ShaderResourceView : public ResourceView
  {
  public:
    virtual ~ShaderResourceView() override {}

  public:
    std::string GetTypeName() override final { return "ShaderResourceView"; }

  public:
    static std::string GetStaticTypeName() { return "ShaderResourceView"; }
  };
}
