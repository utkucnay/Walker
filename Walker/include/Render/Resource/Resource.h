#pragma once

#include <Render/Resource/ResourceTypes.h>

namespace wkr::render
{
  struct FResourceDesc
  {
    u64 alignment;
    u64 width;
    u32 height;
    u16 depthOrArraySize;
    u16 mipLevels;
    FSample sample;
    EResourceFormat format;
    EResourceFlag flag;
    EResourceLayout layout;
    EResourceDimension dimension;
  };

  class IResource
  {
  public:
    virtual ~IResource() = default;

  public:
    virtual NativeObject    GetNativeObject() = 0;
    virtual EResourceState  GetState() = 0;
    virtual std::string     GetTypeName() = 0;
  };

  using IResourceHandle = mem::TRef<IResource>;
}
