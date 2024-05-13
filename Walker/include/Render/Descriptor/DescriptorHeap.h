#pragma once

#include <Render/Descriptor/DescriptorTable.h>
#include <Render/ResourceView/ResourceView.h>
#include <Render/Core/Device.h>
#include <Render/Resource/Texture2D.h>

namespace wkr::render
{
  class DescriptorHeapBuilder;

  class IDescriptorHeap
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
    virtual ~IDescriptorHeap() {}

  public:
    virtual u32 GetCount() = 0;

    virtual IDescriptorHeap::Type  GetType()  = 0;
    virtual IDescriptorHeap::Flags GetFlags() = 0;

    virtual void Bind(
        const std::vector<mem::WeakRef<rsc::IResource>>& resources) = 0;

   // virtual mem::Scope<DescriptorTable> CreateDescriptorTable(
   //     uint32_t offset, uint32_t size);

    template<typename T>
    [[nodiscard]] mem::Ref<T> Get(std::size_t index)
    {
      WKR_CORE_ERROR_COND(
          m_resourceViews[index]->GetTypeName() != T::GetStaticTypeName(),
          "Didn't Match View Type " << m_resourceViews[index]->GetTypeName() << " " << T::GetStaticTypeName());
      return m_resourceViews[index];
    }

  public:
    virtual NativeHandle GetNativeHandle() = 0;

  protected:
    std::vector<mem::Ref<view::UResourceView>> m_resourceViews;
  };

  class DescriptorHeapBuilder : IBuilder<IDescriptorHeap>
  {
  public:
    DescriptorHeapBuilder& SetCount(u32 count);
    DescriptorHeapBuilder& SetType(IDescriptorHeap::Type type);
    DescriptorHeapBuilder& SetFlags(IDescriptorHeap::Flags flags);

  public:
    [[nodiscard]] IDescriptorHeap*             BuildRaw()    override final;
    [[nodiscard]] mem::Ref<IDescriptorHeap>    BuildRef()    override final;
    [[nodiscard]] mem::Scope<IDescriptorHeap>  BuildScope()  override final;

  public:
    u32 m_count{};

    IDescriptorHeap::Type   m_type{};
    IDescriptorHeap::Flags  m_flags{};
  };
}
