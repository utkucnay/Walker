#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class AConstantBufferView : public AResourceView
  {
  public:
    virtual ~AConstantBufferView() override {}

  public:
    std::string GetTypeName() override final { return "ConstantBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "ConstantBufferView"; }
  };
}
