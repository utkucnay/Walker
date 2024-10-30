#pragma once

#include "Graphics/Resource/UTexture2D.h"
#include "Graphics/ResourceView/IResourceView.h"

namespace wkr::render
{
  class ARenderTargetView : public IResourceView
  {
  public:
    virtual ~ARenderTargetView() override = default;

  public:
    mem::TRef<UTexture2D> GetTexture2D()
      { return m_texture2D; }

    std::string GetTypeName() override final { return "RenderTargetView"; }

  public:
    static std::string GetStaticTypeName() { return "RenderTargetView"; }

  protected:
    mem::TRef<UTexture2D> m_texture2D;
  };

  using ARenderTargetViewHandle = mem::TRef<ARenderTargetView>;
}
