#include "Render/PipelineState.h"
#include <Render/RenderMakro.h>
#include <Render/Command.h>
#include <Render/RendererAPI.h>

#include <Platforms/DirectX12/DX12Command.h>

namespace wkr::render
{
  Ref<CommandAllocator> CommandAllocator::Create(
      Ref<Device> device,
      CommandListType listType)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        CreateRef<DX12CommandAllocator>(listType))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<CommandList> CommandList::Create(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        CreateRef<DX12CommandList>(device, commandAllocator))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<CommandList> CommandList::Create(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator,
      Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        CreateRef<DX12CommandList>(device, commandAllocator, pipelineState))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<CommandQueue> CommandQueue::Create(
      Ref<Device> device,
      CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        CreateRef<DX12CommandQueue>(device, desc))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
