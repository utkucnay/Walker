#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class AIndexBufferView : public AResourceView
  {
  public:
    virtual ~AIndexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "IndexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "IndexBufferView"; }
  };
}
