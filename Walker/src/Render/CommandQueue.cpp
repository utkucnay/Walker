#include <Render/Command/CommandQueue.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  //Builder
  CommandQueueBuilder& CommandQueueBuilder::SetCommandListType(
      ICommandList::Type listType)
  {
    m_commandListType = listType;
    return *this;
  }

  CommandQueueBuilder& CommandQueueBuilder::SetCommandQueuePriority(
      ICommandQueue::Priority priority)
  {
    m_commandQueuePriority = priority;
    return *this;
  }

  CommandQueueBuilder& CommandQueueBuilder::SetCommandQueueFlags(
      ICommandQueue::Flags flags)
  {
    m_commandQueueFlags = flags;
    return *this;
  }

  ICommandQueue* CommandQueueBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetCommandQueueFactory()
      ->CreateRaw(*this);
  }

  mem::Ref<ICommandQueue> CommandQueueBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetCommandQueueFactory()
      ->CreateRef(*this);
  }

  mem::Scope<ICommandQueue>CommandQueueBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetCommandQueueFactory()
      ->CreateScope(*this);
  }
}
