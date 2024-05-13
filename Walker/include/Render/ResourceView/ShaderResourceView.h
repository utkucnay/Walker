#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UShaderResourceView : public UResourceView
  {
  public:
    virtual ~UShaderResourceView() override {}

  public:
    std::string GetTypeName() override final { return "ShaderResourceView"; }

  public:
    static std::string GetStaticTypeName() { return "ShaderResourceView"; }
  };
}
