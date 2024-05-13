#pragma once

#include <Render/Command/CommandList.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  //Builder

  CommandListBuilder::CommandListBuilder(
      mem::WeakRef<ICommandAllocator> commandAllocator)
  {
    m_commandAllocator = commandAllocator;
  }

  CommandListBuilder& CommandListBuilder::SetCommandListType(
      ICommandList::Type listType)
  {
    m_listType = listType;
    return *this;
  }

  CommandListBuilder& CommandListBuilder::SetPiplineState(
      mem::WeakRef<IPipelineState> pipelineState)
  {
    //TODO
    //m_pipelineState = pipelineState;
    return *this;
  }

  ICommandList* CommandListBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetCommandListFactory()
      ->CreateRaw(*this);
  }

  mem::Ref<ICommandList> CommandListBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetCommandListFactory()
      ->CreateRef(*this);
  }

  mem::Scope<ICommandList> CommandListBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetCommandListFactory()
      ->CreateScope(*this);
  }
}
