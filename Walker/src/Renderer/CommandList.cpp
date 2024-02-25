#pragma once

#include <Render/Command.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  //Builder
  CommandListBuilder& CommandListBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_listType = listType;
    return *this;
  }

  CommandListBuilder& CommandListBuilder::SetCommandAllocator(
      mem::Ref<CommandAllocator> allocator)
  {
    m_commandAllocator = allocator;
    return *this;
  }

  CommandListBuilder& CommandListBuilder::SetPiplineState(
      mem::Ref<PipelineState> pipelineState)
  {
    m_piplelineState = pipelineState;
    return *this;
  }

  //Factory
  CommandList* CommandListFactory::CreateFactoryRaw(
      mem::Ref<Device> device,
      CommandList::Type listType,
      mem::Ref<CommandAllocator> commandAllocator,
      mem::Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandList(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandList> CommandListFactory::CreateFactoryRef(
      mem::Ref<Device> device,
      CommandList::Type listType,
      mem::Ref<CommandAllocator> commandAllocator,
      mem::Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandList> CommandListFactory::CreateFactoryScope(
      mem::Ref<Device> device,
      CommandList::Type listType,
      mem::Ref<CommandAllocator> commandAllocator,
      mem::Ref<PipelineState> pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
