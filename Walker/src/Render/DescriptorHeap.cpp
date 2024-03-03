#include <Render/Descriptor/DescriptorHeap.h>
#include <Render/Core/RendererMakro.h>

namespace wkr::render
{
  DescriptorHeapBuilder& DescriptorHeapBuilder::SetCount(uint32_t count)
  {
    m_count = count;
    return *this;
  }

  DescriptorHeapBuilder& DescriptorHeapBuilder::SetType(
      DescriptorHeap::Type type)
  {
    m_type = type;
    return *this;
  }

  DescriptorHeapBuilder& DescriptorHeapBuilder::SetFlags(
      DescriptorHeap::Flags flag)
  {
    m_flags = flag;
    return *this;
  }

  DescriptorHeap* DescriptorHeapBuilder::BuildRaw(mem::Visitor<Device> device)
  {
    return mem::Scope<DescriptorHeapFactory>::Create()->
      CreateFactoryRaw(device, this);
  }

  mem::Ref<DescriptorHeap> DescriptorHeapBuilder::BuildRef(
      mem::Visitor<Device> device)
  {
    return mem::Scope<DescriptorHeapFactory>::Create()->
      CreateFactoryRef(device, this);
  }

  mem::Scope<DescriptorHeap> DescriptorHeapBuilder::BuildScope(
      mem::Visitor<Device> device)
  {
    return mem::Scope<DescriptorHeapFactory>::Create()->
      CreateFactoryScope(device, this);
  }

  DescriptorHeap* DescriptorHeapFactory::CreateFactoryRaw(
      mem::Visitor<Device> device,
      mem::Visitor<DescriptorHeapBuilder> dhb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12DescriptorHeap(device, dhb))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<DescriptorHeap> DescriptorHeapFactory::CreateFactoryRef(
      mem::Visitor<Device> device,
      mem::Visitor<DescriptorHeapBuilder> dhb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12DescriptorHeap>::Create(device, dhb))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<DescriptorHeap> DescriptorHeapFactory::CreateFactoryScope(
      mem::Visitor<Device> device,
      mem::Visitor<DescriptorHeapBuilder> dhb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12DescriptorHeap>::Create(device, dhb))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
