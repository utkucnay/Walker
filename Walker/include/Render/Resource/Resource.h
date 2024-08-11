#pragma once

#include <Render/Resource/Heap.h>
#include <Render/Resource/ResourceTypes.h>

namespace wkr::render
{
  struct FResource
  {
    u64 alignment;
    u64 width;
    u32 height;
    u16 depthOrArraySize;
    u16 mipLevels;
    FSample sample;
    EResourceFormat format;
    EResourceF flag;
    EResourceLayout layout;
    EResourceDimension dimension;
  };

  struct FResourceDesc
  {
    EResourceDescType descType;
    union
    {
      FHeapDesc heapDesc;
      struct
      {
        IHeap* heap;
        u64 heapOffset;
      };
    };
    FResource resource;
    EResourceStateF initialState;
    FClearValue* clearValue;
  };

  class IResource
  {
  public:
    virtual ~IResource() = default;

  public:
    virtual NativeObject    GetNativeObject() = 0;
  };

  using IResourceHandle = mem::TRef<IResource>;
}
