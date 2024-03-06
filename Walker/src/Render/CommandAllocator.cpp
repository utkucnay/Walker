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

  CommandAllocator* CommandAllocatorBuilder::BuildRaw(
      Device* device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRaw(device, this);
  }

  mem::Ref<CommandAllocator> CommandAllocatorBuilder::BuildRef(
      Device* device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRef(device, this);
  }

  mem::Scope<CommandAllocator> CommandAllocatorBuilder::BuildScope(
      Device* device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryScope(device, this);
  }
}
