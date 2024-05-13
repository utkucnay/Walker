#include <Render/Core/RendererAPI.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  //Builder
  CommandAllocatorBuilder& CommandAllocatorBuilder::SetCommandListType(
      ICommandList::Type listType)
  {
    m_listType = listType;
    return *this;
  }

  ICommandAllocator* CommandAllocatorBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetCommandAllocaterFactory()
      ->CreateRaw(*this);
  }

  mem::Ref<ICommandAllocator> CommandAllocatorBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetCommandAllocaterFactory()
      ->CreateRef(*this);
  }

  mem::Scope<ICommandAllocator> CommandAllocatorBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetCommandAllocaterFactory()
      ->CreateScope(*this);
  }
}
