#include <Render/Command.h>
#include <Render/RendererMakro.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  CommandAllocator::~CommandAllocator()
  {

  }

  //Builder
  CommandAllocatorBuilder& CommandAllocatorBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_commandListType = listType;
    return *this;
  }

  CommandAllocator* CommandAllocatorBuilder::BuildRaw(Device* device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRaw(device, m_commandListType);
  }

  mem::Ref<CommandAllocator> CommandAllocatorBuilder::BuildRef(Device* device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRef(device, m_commandListType);
  }

  mem::Scope<CommandAllocator> CommandAllocatorBuilder::BuildScope(Device* device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryScope(device, m_commandListType);
  }

  //Factory
  CommandAllocator* CommandAllocatorFactory::CreateFactoryRaw(
      Device* device,
      CommandList::Type listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandAllocator(device, listType))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandAllocator> CommandAllocatorFactory::CreateFactoryRef(
      Device* device,
      CommandList::Type listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12CommandAllocator>::Create(device, listType))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandAllocator> CommandAllocatorFactory::CreateFactoryScope(
      Device* device,
      CommandList::Type listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12CommandAllocator>::Create(device, listType))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
