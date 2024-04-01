#pragma once

#include "Render/Resource/ResourceBuilder.h"
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

  public:
    static std::string GetStaticTypeName() { return "Buffers"; }
  };

  class BuffersBuilder : ResourceBuilder<Buffers>
  {

  private:
    virtual Resource::Dimension GetDimension()
    { return Resource::Dimension::Buffer; }
    virtual mem::Scope<Factory<Buffers, ResourceBuilder*>> GetFactory();
  };

  class GenericBuffersBuilder
  {
  public:
    BuffersBuilder* GetBuilder() { return m_buffersBuilder.Get(); }

  private:
    mem::Scope<BuffersBuilder> m_buffersBuilder;
  };
}
