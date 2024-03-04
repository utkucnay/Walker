#pragma once

#include <Render/Resource/Texture2D.h>
#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class RenderTargetView : public ResourceView
  {
  public:
    virtual ~RenderTargetView() override {}

  public:
    std::string GetTypeName() override final { return "RenderTargetView"; }

    mem::WeakRef<rsc::Texture2D> GetTexture() { return m_resource; }
  };
}
