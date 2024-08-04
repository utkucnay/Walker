#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class ADepthStencilView : public AResourceView
  {
  public:
    virtual ~ADepthStencilView() override {}

  public:
    static std::string GetStaticTypeName() { return "DepthStencilView"; }
  };
}
