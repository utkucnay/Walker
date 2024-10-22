#pragma once

#include "Graphics/ResourceView/IResourceView.h"

namespace wkr::render
{
  class AVertexBufferView : public IResourceView
  {
  public:
    virtual ~AVertexBufferView() override {}

  public:
    std::string GetTypeName() override final { return "VertexBufferView"; }

  public:
    static std::string GetStaticTypeName() { return "VertexBufferView"; }
  };
}
