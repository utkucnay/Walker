#pragma once

#include <Render/Descriptor/DescriptorTable.h>
#include <Render/ResourceView/ResourceView.h>
#include <Render/Core/Device.h>
#include <Render/Resource/Texture2D.h>

namespace wkr::render
{
  class DescriptorHeapBuilder;

  class DescriptorHeap
  {
  public:
    enum class Flags
    {
      None = 0,
      ShaderVisable = 0x1,
    };

    enum class Type
    {
      CBV_SRV_UAV = 0,
      Sampler,
      RTV,
      DSV,
      NumTypes,
    };

  public:
    virtual ~DescriptorHeap() {}

  public:
    virtual uint32_t              GetCount() = 0;
    virtual DescriptorHeap::Type  GetType()  = 0;
    virtual DescriptorHeap::Flags GetFlags() = 0;
    virtual void Bind(
        std::vector<mem::WeakRef<rsc::Resource>> resources) = 0;

   // virtual mem::Scope<DescriptorTable> CreateDescriptorTable(
   //     uint32_t offset, uint32_t size);

    template<typename T>
    T* Get(std::size_t index)
    {
      WKR_CORE_ERROR_COND(
          m_resourceViews[index]->GetTypeName() != T::GetStaticTypeName(),
          "Didn't Match View Type " << m_resourceViews[index]->GetTypeName() << " " << T::GetStaticTypeName());
      return static_cast<T*>(m_resourceViews[index].Get());
    }

  public:
    virtual void* GetNativeHandle() = 0;

  protected:
    std::vector<mem::Scope<view::ResourceView>> m_resourceViews;
  };

  class DescriptorHeapBuilder : Builder<DescriptorHeap>
  {
  public:
    DescriptorHeapBuilder& SetCount(uint32_t count);
    DescriptorHeapBuilder& SetType(DescriptorHeap::Type type);
    DescriptorHeapBuilder& SetFlags(DescriptorHeap::Flags flags);

  public:
    DescriptorHeap*             BuildRaw()    override final;
    mem::Ref<DescriptorHeap>    BuildRef()    override final;
    mem::Scope<DescriptorHeap>  BuildScope()  override final;

  public:
    uint32_t              m_count{};
    DescriptorHeap::Type  m_type{};
    DescriptorHeap::Flags m_flags{};
  };
}
