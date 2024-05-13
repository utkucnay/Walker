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
      IDescriptorHeap::Type type)
  {
    m_type = type;
    return *this;
  }

  DescriptorHeapBuilder& DescriptorHeapBuilder::SetFlags(
      IDescriptorHeap::Flags flag)
  {
    m_flags = flag;
    return *this;
  }

  IDescriptorHeap* DescriptorHeapBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetDescriptorHeapFactory()->
      CreateRaw(*this);
  }

  mem::Ref<IDescriptorHeap> DescriptorHeapBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetDescriptorHeapFactory()->
      CreateRef(*this);
  }

  mem::Scope<IDescriptorHeap> DescriptorHeapBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetDescriptorHeapFactory()->
      CreateScope(*this);
  }
}
