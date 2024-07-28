#pragma once

#include <Render/Descriptor/DescriptorTable.h>
#include <Render/ResourceView/ResourceView.h>
#include <Render/Core/Device.h>
#include <Render/Resource/Texture2D.h>

namespace wkr::render
{
  enum class EDescriptorHeapFlags
  {
    None = 0,
    ShaderVisable = 0x1,
  };

  enum class EDescriptorHeapType
  {
    CBV_SRV_UAV = 0,
    Sampler,
    RTV,
    DSV,
    NumTypes,
  };

  struct FDescriptorHeapDesc
  {
    u32                   m_count;
    EDescriptorHeapType   m_type;
    EDescriptorHeapFlags  m_flags;
  };

  class IDescriptorHeap
  {
  public:
    virtual ~IDescriptorHeap() {}

  public:
    virtual u32 GetCount() = 0;

    virtual IDescriptorHeap::Type  GetType()  = 0;
    virtual IDescriptorHeap::Flags GetFlags() = 0;

    virtual void Bind(
        const std::vector<mem::TWeakRef<rsc::IResource>>& resources) = 0;

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
    std::vector<view::UResourceViewHandle> m_resourceViews;
  };
}
