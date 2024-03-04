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
    CommandQueue(
        CommandList::Type listType,
        CommandQueue::Priority priority,
        CommandQueue::Flags flags) :
      m_listType(listType),
      m_priority(priority),
      m_flags(flags) {}
    virtual ~CommandQueue() = 0;

  public:
    virtual void ExecuteCommandList(
        std::vector<mem::Scope<CommandList>> commandLists);

    virtual void* GetNativeHandle() = 0;

  protected:
    CommandList::Type       m_listType;
    CommandQueue::Priority  m_priority;
    CommandQueue::Flags     m_flags;

    friend class CommandQueueBuilder;
  };

  class CommandQueueBuilder : Builder<
                              CommandQueue,
                              mem::Visitor<Device>>
  {
  public:
    CommandQueueBuilder& SetCommandListType(CommandList::Type listType);
    CommandQueueBuilder& SetCommandQueuePriority(
        CommandQueue::Priority priority);
    CommandQueueBuilder& SetCommandQueueFlags(
        CommandQueue::Flags    flags);

  public:
    CommandQueue*             BuildRaw  (
        mem::Visitor<Device> device) override;
    mem::Ref<CommandQueue>    BuildRef  (
        mem::Visitor<Device> device) override;
    mem::Scope<CommandQueue>  BuildScope(
        mem::Visitor<Device> device) override;

  private:
    CommandList::Type       m_commandListType{};
    CommandQueue::Priority  m_commandQueuePriority{};
    CommandQueue::Flags     m_commandQueueFlags{};
  };

  class CommandQueueFactory : Factory<
                                    CommandQueue,
                                    mem::Visitor<Device>,
                                    CommandList::Type,
                                    CommandQueue::Priority,
                                    CommandQueue::Flags>
  {
  public:
    CommandQueue*       CreateFactoryRaw   (
        mem::Visitor<Device>    device,
        CommandList::Type       commandType,
        CommandQueue::Priority  queuePriorty,
        CommandQueue::Flags     flags) override final;

    mem::Ref<CommandQueue>    CreateFactoryRef  (
        mem::Visitor<Device>       device,
        CommandList::Type       commandType,
        CommandQueue::Priority  queuePriorty,
        CommandQueue::Flags     flags) override final;

    mem::Scope<CommandQueue>  CreateFactoryScope(
        mem::Visitor<Device>       device,
        CommandList::Type       commandType,
        CommandQueue::Priority  queuePriorty,
        CommandQueue::Flags     flags) override final;
  };
}
