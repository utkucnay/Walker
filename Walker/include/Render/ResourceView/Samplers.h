#pragma once

#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class ASamplers : public AResourceView
  {
  public:
    virtual ~ASamplers() override {}

  public:
    std::string GetTypeName() override final { return "Samplers"; }

  public:
    static std::string GetStaticTypeName() { return "Samplers"; }
  };
}
