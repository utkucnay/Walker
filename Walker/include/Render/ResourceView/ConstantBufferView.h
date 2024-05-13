#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UConstantBufferView : public UResourceView
  {
  public:
    virtual ~UConstantBufferView() override {}

  public:
    std::string GetTypeName() override final { return "ConstantBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "ConstantBufferView"; }
  };
}
