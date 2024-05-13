#pragma once

#include "Render/Resource/Heap.h"
#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  enum class ResourceBuilderType
  {
    Committed ,
    Reserved  ,
    Placed    ,
  };

  template<typename T>
  class ResourceBuilder : IBuilder<T>
  {
  public:
    ResourceBuilder& SetType(ResourceBuilderType type)
    { m_type = type; return *this; }
    ResourceBuilder& SetHeapBuilder(const HeapBuilder& hb)
    { m_heapBuilder = hb; return *this; }
    ResourceBuilder& SetHeap(mem::WeakRef<IHeap> heap)
    { m_heap = heap; return *this; }
    ResourceBuilder& SetHeapOffset(u64 heapOffset)
    { m_heapOffset = heapOffset; return *this; }
    ResourceBuilder& SetState(IResource::State state)
    { m_state = state; return *this; }
    ResourceBuilder& SetAlignment(u64 alignment)
    { m_alignment = alignment; return *this;}
    ResourceBuilder& SetWidth(u64 width)
    { m_width = width; return *this; }
    ResourceBuilder& SetHeight(u32 height)
    { m_height = height; return *this; }
    ResourceBuilder& SetDepthOrArraySize(u16 depthOrArraySize)
    { m_depthOrArraySize = depthOrArraySize; return *this; }
    ResourceBuilder& SetMipLevels(u16 mipLevels)
    { m_mipLevels = mipLevels; return *this; }
    ResourceBuilder& SetFormat(IResource::Format format)
    { m_format = format; return *this; }
    ResourceBuilder& SetSample(FSample sample)
    { m_sample = sample; return *this; }
    ResourceBuilder& SetTextureLayout(IResource::Layout layout)
    { m_layout = layout; return *this;}
    ResourceBuilder& SetFlag(IResource::Flag flag)
    { m_flag = flag; return *this; }
    virtual IResource::Dimension GetDimension() = 0;

  public:
    [[nodiscard]] T*            BuildRaw()   override
      { return GetFactory()->CreateRaw(*this); }
    [[nodiscard]] mem::Ref<T>   BuildRef()   override
      { return GetFactory()->CreateRef(*this); }
    [[nodiscard]] mem::Scope<T> BuildScope() override
      { return GetFactory()->CreateScope(*this);}

  private:
    virtual mem::Scope<IFactory<T, ResourceBuilder&>> GetFactory() = 0;

  public:
    ResourceBuilderType m_type;
    HeapBuilder m_heapBuilder;
    mem::WeakRef<IHeap> m_heap;
    u64 m_heapOffset;
    IResource::State m_state;
    u64 m_alignment;
    u64 m_width;
    u32 m_height;
    u16 m_depthOrArraySize;
    u16 m_mipLevels;
    IResource::Format m_format;
    FSample m_sample;
    IResource::Layout m_layout;
    IResource::Flag m_flag;
  };
}
