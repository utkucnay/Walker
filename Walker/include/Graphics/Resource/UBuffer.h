#pragma once

#include "Graphics/Resource/IResource.h"
#include "Graphics/Resource/ResourceType.h"

namespace wkr::render
{
  struct FBufferDesc
  {
    EHeapType heapType;
    u64 bufferSize;
    EResourceStateF initState;
    FClearValue* clearValue;
    EResourceF resourceFlag;
  };

  class UBuffer
  {
  public:
    UBuffer(FBufferDesc& buffersDesc);
    UBuffer(IResourceHandle resource) : m_resource(resource) {};
    ~UBuffer();

  public:
    FBufferDesc GetDesc() const;

  private:
    IResourceHandle m_resource;
  };
}
