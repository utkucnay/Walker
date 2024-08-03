#pragma once

#include <Render/Command/CommandTypes.h>
#include <Render/Command/CommandList.h>
#include <Render/Core/Fence.h>

namespace wkr::render
{
  struct FCommandQueueDesc
  {
    ECommandType            m_commandType{};
    ECommandQueuePriority   m_commandQueuePriority{};
    ECommandQueueFlags      m_commandQueueFlags{};
  };

  class ICommandQueue
  {
  public:
    virtual ~ICommandQueue() {}

  public:
    virtual void ExecuteCommandList(
        const std::vector<ICommandList*>& commandLists) = 0;

    virtual void Signal(IFence& fence, i32 frameIndex) = 0;

    virtual NativeObject GetNativeObject() = 0;
  };

  using ICommandQueueHandle = mem::TRef<ICommandQueue>;
}
