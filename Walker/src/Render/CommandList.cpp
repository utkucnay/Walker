#pragma once

#include <Render/Command.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  CommandList::~CommandList()
  {

  }

  //Builder
  CommandListBuilder& CommandListBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_listType = listType;
    return *this;
  }

  CommandListBuilder& CommandListBuilder::SetCommandAllocator(
      CommandAllocator* allocator)
  {
    m_commandAllocator = allocator;
    return *this;
  }

  CommandListBuilder& CommandListBuilder::SetPiplineState(
      PipelineState* pipelineState)
  {
    m_piplelineState = pipelineState;
    return *this;
  }

  CommandList* CommandListBuilder::BuildRaw(Device* device)
  {
    return mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryRaw(
          device,
          m_listType,
          m_commandAllocator,
          m_piplelineState);
  }

  mem::Ref<CommandList> CommandListBuilder::BuildRef(Device* device)
  {
    return mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryRef(
          device,
          m_listType,
          m_commandAllocator,
          m_piplelineState);
  }

  mem::Scope<CommandList> CommandListBuilder::BuildScope(Device* device)
  {
    return mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryScope(
          device,
          m_listType,
          m_commandAllocator,
          m_piplelineState);
  }

  //Factory
  CommandList* CommandListFactory::CreateFactoryRaw(
      Device*           device,
      CommandList::Type listType,
      CommandAllocator* commandAllocator,
      PipelineState*    pipelineState)
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
      Device* device,
      CommandList::Type listType,
      CommandAllocator* commandAllocator,
      PipelineState* pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandList> CommandListFactory::CreateFactoryScope(
      Device*           device,
      CommandList::Type listType,
      CommandAllocator* commandAllocator,
      PipelineState*    pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
