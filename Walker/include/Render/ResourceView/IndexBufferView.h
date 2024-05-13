#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UIndexBufferView : public UResourceView
  {
  public:
    virtual ~UIndexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "IndexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "IndexBufferView"; }
  };
}
