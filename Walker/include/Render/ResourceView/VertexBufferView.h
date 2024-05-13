#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UVertexBufferView : public UResourceView
  {
  public:
    virtual ~UVertexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "VertexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "VertexBufferView"; }
  };
}
