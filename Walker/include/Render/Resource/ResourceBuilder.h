#pragma once

#include "Render/Resource/Heap.h"
#include <Render/Resource/Resource.h>
#include <Render/Resource/Texture.h>

namespace wkr::render::rsc
{
  enum class ResourceBuilderType
  {
    Committed ,
    Reserved  ,
    Placed    ,
  };

  template<typename T>
  class ResourceBuilder : Builder<T>
  {
  public:
    ResourceBuilder& SetType(ResourceBuilderType type)
    { m_type = type; return *this; }
    ResourceBuilder& SetHeapBuilder(const HeapBuilder& hb)
    { m_heapBuilder = hb; return *this; }
    ResourceBuilder& SetHeap(Heap* heap)
    { m_heap = heap; return *this; }
    ResourceBuilder& SetHeapOffset(uint64_t heapOffset)
    { m_heapOffset = heapOffset; return *this; }
    ResourceBuilder& SetState(Resource::State state)
    { m_state = state; return *this; }
    ResourceBuilder& SetAlignment(uint64_t alignment)
    { m_alignment = alignment; return *this;}
    ResourceBuilder& SetWidth(uint64_t width)
    { m_width = width; return *this; }
    ResourceBuilder& SetHeight(uint32_t height)
    { m_height = height; return *this; }
    ResourceBuilder& SetDepthOrArraySize(uint16_t depthOrArraySize)
    { m_depthOrArraySize = depthOrArraySize; return *this; }
    ResourceBuilder& SetMipLevels(uint16_t mipLevels)
    { m_mipLevels = mipLevels; return *this; }
    ResourceBuilder& SetFormat(Format format)
    { m_format = format; return *this; }
    ResourceBuilder& SetSample(SampleDesc sample)
    { m_sample = sample; return *this; }
    ResourceBuilder& SetTextureLayout(Texture::Layout layout)
    { m_layout = layout; return *this;}
    ResourceBuilder& SetFlag(Resource::Flag flag)
    { m_flag = flag; return *this; }
    virtual Resource::Dimension GetDimension() = 0;

  public:
    T*            BuildRaw()   override { return GetFactory()->CreateFactoryRaw(this); }
    mem::Ref<T>   BuildRef()   override { return GetFactory()->CreateFactoryRef(this); }
    mem::Scope<T> BuildScope() override { return GetFactory()->CreateFactoryScope(this);}

  private:
    virtual mem::Scope<Factory<T, ResourceBuilder*>> GetFactory() = 0;

  public:
    ResourceBuilderType m_type;
    HeapBuilder m_heapBuilder;
    Heap* m_heap;
    uint64_t m_heapOffset;
    Resource::State m_state;
    uint64_t m_alignment;
    uint64_t m_width;
    uint32_t m_height;
    uint16_t m_depthOrArraySize;
    uint16_t m_mipLevels;
    Format m_format;
    SampleDesc m_sample;
    Texture::Layout m_layout;
    Resource::Flag m_flag;
  };
}
