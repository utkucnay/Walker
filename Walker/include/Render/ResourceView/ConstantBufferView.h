#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class ConstantBufferView : public ResourceView
  {
  public:
    virtual ~ConstantBufferView() override {}

  public:
    std::string GetTypeName() override final { return "ConstantBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "ConstantBufferView"; }
  };
}
