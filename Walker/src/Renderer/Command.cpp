#include <Render/Command.h>

#include <Render/PipelineState.h>
#include <Render/RendererMakro.h>
#include <Render/RendererAPI.h>

namespace wkr::render
{
  CommandAllocator* CommandAllocatorFactory::CreateFactoryRaw(
      Ref<Device> device,
      CommandListType listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandAllocator(device, listType))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<CommandAllocator> CommandAllocatorFactory::CreateFactoryRef(
      Ref<Device> device,
      CommandListType listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12CommandAllocator>::Create(device, listType))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Scope<CommandAllocator> CommandAllocatorFactory::CreateFactoryScope(
      Ref<Device> device,
      CommandListType listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12CommandAllocator>::Create(device, listType))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  CommandList* CommandListFactory::CreateFactoryRaw(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator,
      Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandList(device, commandAllocator, pipelineState))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<CommandList> CommandListFactory::CreateFactoryRef(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator,
      Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12CommandList>::Create(device, commandAllocator, pipelineState))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Scope<CommandList> CommandListFactory::CreateFactoryScope(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator,
      Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12CommandList>::Create(device, commandAllocator, pipelineState))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  CommandQueue* CommandQueueFactory::CreateFactoryRaw(
      Ref<Device> device,
      CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandQueue(device, desc))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<CommandQueue> CommandQueueFactory::CreateFactoryRef(
      Ref<Device> device,
      CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12CommandQueue>::Create(device, desc))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Scope<CommandQueue> CommandQueueFactory::CreateFactoryScope(
      Ref<Device> device,
      CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12CommandQueue>::Create(device, desc))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
