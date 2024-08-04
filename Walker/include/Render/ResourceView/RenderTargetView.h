#pragma once

#include <Render/Resource/Texture2D.h>
#include <Render/ResourceView/ResourceView.h>

namespace wkr::render
{
  class ARenderTargetView : public AResourceView
  {
  public:
    virtual ~ARenderTargetView() override = default;

  public:
    mem::TWeakRef<ITexture2D> GetTexture2D()
      { return GetResource<ITexture2D>(); }

    std::string GetTypeName() override final { return "RenderTargetView"; }

  public:
    static std::string GetStaticTypeName() { return "RenderTargetView"; }
  };

  using ARenderTargetViewHandle = mem::TRef<ARenderTargetView>;
}
