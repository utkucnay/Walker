#pragma once

#include <Render/Resource/Texture2D.h>
#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class URenderTargetView : public UResourceView
  {
  public:
    virtual ~URenderTargetView() override {}

  public:
    mem::WeakRef<rsc::ITexture2D> GetTexture()
      { return GetResource<rsc::ITexture2D>(); }
    std::string GetTypeName() override final { return "RenderTargetView"; }

  public:
    static std::string GetStaticTypeName() { return "RenderTargetView"; }
  };
}
