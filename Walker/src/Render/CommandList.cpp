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

  CommandList* CommandListBuilder::BuildRaw(
      mem::Visitor<Device> device)
  {
    return mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryRaw(
          device,
          m_listType,
          m_commandAllocator,
          m_piplelineState);
  }

  mem::Ref<CommandList> CommandListBuilder::BuildRef(
      mem::Visitor<Device> device)
  {
    return mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryRef(
          device,
          m_listType,
          m_commandAllocator,
          m_piplelineState);
  }

  mem::Scope<CommandList> CommandListBuilder::BuildScope(
      mem::Visitor<Device> device)
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
      mem::Visitor<Device>            device,
      CommandList::Type               listType,
      mem::Visitor<CommandAllocator>  commandAllocator,
      PipelineState*                  pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        (NULL == pipelineState) ?
        new DX12CommandList(
          device,
          listType,
          commandAllocator) :
        new DX12CommandList(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandList> CommandListFactory::CreateFactoryRef(
      mem::Visitor<Device>            device,
      CommandList::Type               listType,
      mem::Visitor<CommandAllocator>  commandAllocator,
      PipelineState*                  pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        (NULL == pipelineState) ?
        mem::Ref<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator) :
        mem::Ref<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandList> CommandListFactory::CreateFactoryScope(
      mem::Visitor<Device>            device,
      CommandList::Type               listType,
      mem::Visitor<CommandAllocator>  commandAllocator,
      PipelineState*                  pipelineState)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        (NULL == pipelineState) ?
        mem::Scope<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator) :
        mem::Scope<DX12CommandList>::Create(
          device,
          listType,
          commandAllocator,
          pipelineState))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
