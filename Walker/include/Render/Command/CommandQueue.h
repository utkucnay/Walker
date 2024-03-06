#pragma once

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
    virtual ~CommandQueue() = 0;

  public:
    virtual void ExecuteCommandList(
        std::vector<CommandList*> commandLists);

    virtual void* GetNativeHandle() = 0;

  protected:
    CommandList::Type       m_listType;
    CommandQueue::Priority  m_priority;
    CommandQueue::Flags     m_flags;

    friend class CommandQueueBuilder;
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
