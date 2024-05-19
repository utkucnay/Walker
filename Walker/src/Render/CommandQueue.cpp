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

  REGISTER_BUILDER(I, CommandQueue);
}
