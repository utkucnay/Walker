#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UnorderedAccessView : public ResourceView
  {
  public:
    virtual ~UnorderedAccessView() override {}

  public:
    std::string GetTypeName() override final { return "UnorderedAccessView"; }

  public:
    static std::string GetStaticTypeName() { return "UnorderedAccessView"; }
  };
}
