#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class Samplers : public ResourceView
  {
  public:
    virtual ~Samplers() override {}

  public:
    std::string GetTypeName() override final { return "Samplers"; }

  public:
    static std::string GetStaticTypeName() { return "Samplers"; }
  };
}
