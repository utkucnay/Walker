#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class DepthStencilView : public ResourceView
  {
  public:
    virtual ~DepthStencilView() override {}

  public:
    static std::string GetStaticTypeName() { return "DepthStencilView"; }
  };
}
