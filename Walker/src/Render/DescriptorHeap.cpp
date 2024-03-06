#include <Render/Descriptor/DescriptorHeap.h>
#include <Render/Core/RendererAPI.h>

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

  DescriptorHeap* DescriptorHeapBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetDescriptorHeapFactory()->
      CreateFactoryRaw(this);
  }

  mem::Ref<DescriptorHeap> DescriptorHeapBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetDescriptorHeapFactory()->
      CreateFactoryRef(this);
  }

  mem::Scope<DescriptorHeap> DescriptorHeapBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetDescriptorHeapFactory()->
      CreateFactoryScope(this);
  }
}
