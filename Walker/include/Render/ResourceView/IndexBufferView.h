#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class IndexBufferView : public ResourceView
  {
  public:
    virtual ~IndexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "IndexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "IndexBufferView"; }
  };
}
