#include <Render/Core/RendererAPI.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  //Builder
  CommandAllocatorBuilder& CommandAllocatorBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_listType = listType;
    return *this;
  }

  CommandAllocator* CommandAllocatorBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandAllocaterFactory()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<CommandAllocator> CommandAllocatorBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandAllocaterFactory()
      ->CreateFactoryRef(this);
  }

  mem::Scope<CommandAllocator> CommandAllocatorBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandAllocaterFactory()
      ->CreateFactoryScope(this);
  }
}
