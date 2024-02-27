#pragma once

#include <Render/Device.h>

#if !defined (COMMAND_INCLUDE_BARRIER)
  #error "Command Didn't Include Correctly"
#endif

namespace wkr::render
{
  class Device;

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
    virtual void* GetNativeHandle() = 0;
  };

  struct CommandQueueDesc
  {
    CommandList::Type       m_commandListType;
    CommandQueue::Priority  m_commandQueuePriority;
    CommandQueue::Flags     m_commandQueueFlags;
  };

  class CommandQueueBuilder : Builder<CommandQueue, Device*>
  {
  public:
    CommandQueueBuilder& SetCommandListType(CommandList::Type listType);
    CommandQueueBuilder& SetCommandQueuePriority(CommandQueue::Priority priority);
    CommandQueueBuilder& SetCommandQueueFlags   (CommandQueue::Flags    flags);

  public:
    CommandQueue*             BuildRaw  (Device* device) override;
    mem::Ref<CommandQueue>    BuildRef  (Device* device) override;
    mem::Scope<CommandQueue>  BuildScope(Device* device) override;

  private:
    CommandList::Type       m_commandListType;
    CommandQueue::Priority  m_commandQueuePriority;
    CommandQueue::Flags     m_commandQueueFlags;
  };

  class CommandQueueFactory : Factory<
                                    CommandQueue,
                                    Device*,
                                    const CommandQueueDesc&>
  {
  public:
    CommandQueue*       CreateFactoryRaw   (
        Device*       device,
        const CommandQueueDesc& desc) override;

    mem::Ref<CommandQueue>    CreateFactoryRef  (
        Device*       device,
        const CommandQueueDesc& desc) override;

    mem::Scope<CommandQueue>  CreateFactoryScope(
        Device*       device,
        const CommandQueueDesc& desc) override;
  };
}
