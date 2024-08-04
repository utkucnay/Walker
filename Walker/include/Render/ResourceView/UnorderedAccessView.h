#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class AUnorderedAccessView : public AResourceView
  {
  public:
    virtual ~AUnorderedAccessView() override {}

  public:
    std::string GetTypeName() override final { return "UnorderedAccessView"; }

  public:
    static std::string GetStaticTypeName() { return "UnorderedAccessView"; }
  };
}
