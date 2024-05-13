#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UDepthStencilView : public UResourceView
  {
  public:
    virtual ~UDepthStencilView() override {}

  public:
    static std::string GetStaticTypeName() { return "DepthStencilView"; }
  };
}
