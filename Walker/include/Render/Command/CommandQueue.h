#pragma once

#include <Render/Core/Fence.h>
#include <Render/Command/Command.h>
#include <Render/Core/Device.h>

#if !defined (COMMAND_INCLUDE_BARRIER)
  #error "Command Didn't Include Correctly"
#endif

namespace wkr::render
{
  class ICommandQueue
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
    virtual ~ICommandQueue() {}

  public:
    virtual void ExecuteCommandList(
        const std::vector<mem::Ref<ICommandList>>& commandLists) = 0;

    virtual void Signal(IFence& fence, int frameIndex) = 0;

    virtual NativeHandle GetNativeHandle() = 0;
  };

  class CommandQueueBuilder : IBuilder<ICommandQueue>
  {
  public:
    CommandQueueBuilder& SetCommandListType(
        ICommandList::Type listType);
    CommandQueueBuilder& SetCommandQueuePriority(
        ICommandQueue::Priority priority);
    CommandQueueBuilder& SetCommandQueueFlags(
        ICommandQueue::Flags    flags);

  public:
    [[nodiscard]] ICommandQueue*             BuildRaw  () override;
    [[nodiscard]] mem::Ref<ICommandQueue>    BuildRef  () override;
    [[nodiscard]] mem::Scope<ICommandQueue>  BuildScope() override;

  public:
    ICommandList::Type       m_commandListType{};
    ICommandQueue::Priority  m_commandQueuePriority{};
    ICommandQueue::Flags     m_commandQueueFlags{};
  };
}
