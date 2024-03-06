#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class VertexBufferView : public ResourceView
  {
  public:
    virtual ~VertexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "VertexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "VertexBufferView"; }
  };
}
