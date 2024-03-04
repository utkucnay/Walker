#pragma once

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
        mem::Visitor<Device> device,
        int count,
        std::vector<mem::WeakRef<rsc::Resource>> resources) = 0;

    template<typename T>
    mem::Visitor<T> Get(std::size_t index)
    {
      return m_resourceViews[index].Get();
    }

  public:
    virtual void* GetNativeHandle() = 0;

  protected:
    std::vector<mem::Scope<view::ResourceView>> m_resourceViews;
  };

  class DescriptorHeapBuilder : Builder<
                                DescriptorHeap,
                                mem::Visitor<Device>>
  {
  public:
    DescriptorHeapBuilder& SetCount(uint32_t count);
    DescriptorHeapBuilder& SetType(DescriptorHeap::Type type);
    DescriptorHeapBuilder& SetFlags(DescriptorHeap::Flags flags);

  public:
    DescriptorHeap*             BuildRaw(
        mem::Visitor<Device> device) override final;
    mem::Ref<DescriptorHeap>    BuildRef(
        mem::Visitor<Device> device) override final;
    mem::Scope<DescriptorHeap>  BuildScope(
        mem::Visitor<Device> device) override final;

  public:
    uint32_t              m_count{};
    DescriptorHeap::Type  m_type{};
    DescriptorHeap::Flags m_flags{};

    friend class DescriptorHeap;
  };

  class DescriptorHeapFactory : Factory<
                                DescriptorHeap,
                                mem::Visitor<Device>,
                                mem::Visitor<DescriptorHeapBuilder>>
  {
  public:
    DescriptorHeap* CreateFactoryRaw(
        mem::Visitor<Device> device,
        mem::Visitor<DescriptorHeapBuilder> dhb) override final;
    mem::Ref<DescriptorHeap> CreateFactoryRef(
        mem::Visitor<Device> device,
        mem::Visitor<DescriptorHeapBuilder> dhb) override final;
    mem::Scope<DescriptorHeap> CreateFactoryScope(
        mem::Visitor<Device> device,
        mem::Visitor<DescriptorHeapBuilder> dhb) override final;
  };
}
