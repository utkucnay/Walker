#pragma once

#include <Render/Core/Fence.h>
#include <Render/Command/Command.h>
#include <Render/Core/Device.h>

#if !defined (COMMAND_INCLUDE_BARRIER)
  #error "Command Didn't Include Correctly"
#endif

namespace wkr::render
{
  class Device;
  class CommandQueueBuilder;

  class CommandQueue
  {
  public:
    enum class Flags
    {
      None              = 0,
      DisableGPUTimeout = 0x1
    };

    enum class Priority
    {
      Normal   = 0,
      High     = 100,
      Realtime = 10000
    };

  public:
    virtual ~CommandQueue() {}

  public:
    virtual void ExecuteCommandList(
        std::vector<CommandList*> commandLists) = 0;

    virtual void Signal(Fence* fence, int frameIndex) = 0;

    virtual void* GetNativeHandle() = 0;
  };

  class CommandQueueBuilder : Builder<CommandQueue>
  {
  public:
    CommandQueueBuilder& SetCommandListType(CommandList::Type listType);
    CommandQueueBuilder& SetCommandQueuePriority(
        CommandQueue::Priority priority);
    CommandQueueBuilder& SetCommandQueueFlags(
        CommandQueue::Flags    flags);

  public:
    CommandQueue*             BuildRaw  () override;
    mem::Ref<CommandQueue>    BuildRef  () override;
    mem::Scope<CommandQueue>  BuildScope() override;

  public:
    CommandList::Type       m_commandListType{};
    CommandQueue::Priority  m_commandQueuePriority{};
    CommandQueue::Flags     m_commandQueueFlags{};
  };
}
