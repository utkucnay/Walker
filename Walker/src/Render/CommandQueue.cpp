#include <Render/Command/CommandQueue.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  //Builder
  CommandQueueBuilder& CommandQueueBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_commandListType = listType;
    return *this;
  }

  CommandQueueBuilder& CommandQueueBuilder::SetCommandQueuePriority(
      CommandQueue::Priority priority)
  {
    m_commandQueuePriority = priority;
    return *this;
  }

  CommandQueueBuilder& CommandQueueBuilder::SetCommandQueueFlags(
      CommandQueue::Flags flags)
  {
    m_commandQueueFlags = flags;
    return *this;
  }

  CommandQueue* CommandQueueBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandQueueFactory()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<CommandQueue> CommandQueueBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandQueueFactory()
      ->CreateFactoryRef(this);
  }

  mem::Scope<CommandQueue>CommandQueueBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetCommandQueueFactory()
      ->CreateFactoryScope(this);
  }
}
