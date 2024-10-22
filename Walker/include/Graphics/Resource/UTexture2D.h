#pragma once

#include "Graphics/Resource/IResource.h"

namespace wkr::render
{
  struct FTexture2DDesc
  {
    EHeapType heapType;
    EResourceFormat resourceFormat;
    u64 width;
    u32 height;
    FSample sample;
    EResourceF resourceFlag;
    EResourceLayout resourceLayout;
    EResourceStateF initialState;
    FClearValue* clearValue;
  };

  class UTexture2D
  {
  public:
    UTexture2D(FTexture2DDesc& texture2DDesc);
    UTexture2D(IResourceHandle resource) : m_resource(resource) {};

  public:
    FTexture2DDesc GetDesc() const;
    IResourceHandle GetResource() { return m_resource; }

  private:
    IResourceHandle m_resource;
  };
}
