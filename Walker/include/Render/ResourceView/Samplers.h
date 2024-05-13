#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class USamplers : public UResourceView
  {
  public:
    virtual ~USamplers() override {}

  public:
    std::string GetTypeName() override final { return "Samplers"; }

  public:
    static std::string GetStaticTypeName() { return "Samplers"; }
  };
}
