#pragma once

#include <Render/Command/CommandList.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  CommandList::CommandList(mem::Visitor<CommandListBuilder> clb)
  {
    m_type = clb->m_listType;
  }

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
          this);
  }

  mem::Ref<CommandList> CommandListBuilder::BuildRef(
      mem::Visitor<Device> device)
  {
    return  mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryRef(
          device,
          this);
  }

  mem::Scope<CommandList> CommandListBuilder::BuildScope(
      mem::Visitor<Device> device)
  {
    return mem::Scope<CommandListFactory>::Create()
      ->CreateFactoryScope(
          device,
          this);
  }

  //Factory
  CommandList* CommandListFactory::CreateFactoryRaw(
      mem::Visitor<Device>                  device,
      mem::Visitor<CommandListBuilder> cab)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandList(
          device,
          cab))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandList> CommandListFactory::CreateFactoryRef(
      mem::Visitor<Device>            device,
      mem::Visitor<CommandListBuilder> cab)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12CommandList>::Create(
          device,
          cab))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandList> CommandListFactory::CreateFactoryScope(
      mem::Visitor<Device>            device,
      mem::Visitor<CommandListBuilder> cab)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12CommandList>::Create(
          device,
          cab))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
