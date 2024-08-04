#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class AVertexBufferView : public AResourceView
  {
  public:
    virtual ~AVertexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "VertexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "VertexBufferView"; }
  };
}
