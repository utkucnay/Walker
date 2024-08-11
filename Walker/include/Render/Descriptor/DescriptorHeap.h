#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceView/ResourceView.h>
#include <Render/Descriptor/DescriptorTypes.h>

namespace wkr::render
{
  struct FDescriptorHeapDesc
  {
    u32                   m_count;
    EDescriptorHeapType   m_type;
    EDescriptorHeapFlags  m_flags;
  };

  class IDescriptorHeap
  {
  public:
    virtual ~IDescriptorHeap() = default;

  public:
    virtual u32 GetCount() = 0;

    virtual EDescriptorHeapType  GetType()  = 0;
    virtual EDescriptorHeapFlags GetFlags() = 0;

    virtual void Bind(
        const std::vector<IResourceHandle>& resources) = 0;

   // virtual mem::Scope<DescriptorTable> CreateDescriptorTable(
   //     uint32_t offset, uint32_t size);

    template<typename T>
    [[nodiscard]] mem::TRef<T> Get(std::size_t index)
    {
      WKR_CORE_ERROR_COND(
          m_resourceViews[index]->GetTypeName() != T::GetStaticTypeName(),
          "Didn't Match View Type " << m_resourceViews[index]->GetTypeName() << " " << T::GetStaticTypeName());
      return m_resourceViews[index];
    }

  public:
    virtual NativeObject GetNativeObject() = 0;

  protected:
    std::vector<IResourceViewHandle> m_resourceViews;
  };

  using IDescriptorHeapHandle = mem::TRef<IDescriptorHeap>;
}
