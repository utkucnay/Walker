#pragma once

#include <Render/Command/CommandList.h>
#include <Render/Core/RendererAPI.h>

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

  CommandList* CommandListBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandListFactory()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<CommandList> CommandListBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandListFactory()
      ->CreateFactoryRef(this);
  }

  mem::Scope<CommandList> CommandListBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandListFactory()
      ->CreateFactoryScope(this);
  }
}
