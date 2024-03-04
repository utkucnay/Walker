#include <Render/Core/RendererAPI.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  CommandAllocator::CommandAllocator(
      mem::Visitor<CommandAllocatorBuilder> cab)
  {
    m_listType = cab->m_commandListType;
  }

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

  CommandAllocator* CommandAllocatorBuilder::BuildRaw(
      mem::Visitor<Device> device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRaw(device, this);
  }

  mem::Ref<CommandAllocator> CommandAllocatorBuilder::BuildRef(
      mem::Visitor<Device> device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryRef(device, this);
  }

  mem::Scope<CommandAllocator> CommandAllocatorBuilder::BuildScope(
      mem::Visitor<Device> device)
  {
    return mem::Scope<CommandAllocatorFactory>::Create()
      ->CreateFactoryScope(device, this);
  }

  //Factory
  CommandAllocator* CommandAllocatorFactory::CreateFactoryRaw(
      mem::Visitor<Device>                  device,
      mem::Visitor<CommandAllocatorBuilder> cab)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandAllocator(device, cab))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandAllocator> CommandAllocatorFactory::CreateFactoryRef(
      mem::Visitor<Device>                  device,
      mem::Visitor<CommandAllocatorBuilder> cab)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12CommandAllocator>::Create(device, cab))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandAllocator> CommandAllocatorFactory::CreateFactoryScope(
      mem::Visitor<Device>                  device,
      mem::Visitor<CommandAllocatorBuilder> cab)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12CommandAllocator>::Create(device, cab))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
