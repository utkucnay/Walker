#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class RenderTargetView : public ResourceView
  {
  public:
    virtual ~RenderTargetView() override {}

  public:
    std::string GetTypeName() override final { return "RenderTargetView"; }

  public:
    static std::string GetStaticTypeName() { return "RenderTargetView"; }
  };
}
