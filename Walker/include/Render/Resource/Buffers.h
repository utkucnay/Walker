#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Buffers : public Resource
  {
  public:
    virtual ~Buffers() override {}

  public:
    std::string GetTypeName() override final { return "Buffers"; }

    virtual uint64_t GetSize() = 0;
  };
}
