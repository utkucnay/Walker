#include <Render/Command.h>
#include <Render/RendererMakro.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  //Builder
  CommandAllocatorBuilder& CommandAllocatorBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_commandListType = listType;
    return *this;
  }

  CommandAllocator* CommandAllocatorBuilder::BuildRaw(mem::Ref<Device> device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRaw(device, m_commandListType);
  }

  mem::Ref<CommandAllocator> CommandAllocatorBuilder::BuildRef(mem::Ref<Device> device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRef(device, m_commandListType);
  }

  mem::Scope<CommandAllocator> CommandAllocatorBuilder::BuildScope(mem::Ref<Device> device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryScope(device, m_commandListType);
  }

  //Factory
  CommandAllocator* CommandAllocatorFactory::CreateFactoryRaw(
      mem::Ref<Device> device,
      CommandList::Type listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandAllocator(device, listType))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandAllocator> CommandAllocatorFactory::CreateFactoryRef(
      mem::Ref<Device> device,
      CommandList::Type listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12CommandAllocator>::Create(device, listType))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandAllocator> CommandAllocatorFactory::CreateFactoryScope(
      mem::Ref<Device> device,
      CommandList::Type listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12CommandAllocator>::Create(device, listType))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
