#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class UUnorderedAccessView : public UResourceView
  {
  public:
    virtual ~UUnorderedAccessView() override {}

  public:
    std::string GetTypeName() override final { return "UnorderedAccessView"; }

  public:
    static std::string GetStaticTypeName() { return "UnorderedAccessView"; }
  };
}
