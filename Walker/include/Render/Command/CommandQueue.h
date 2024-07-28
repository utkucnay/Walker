#pragma once

#include <Render/Core/Fence.h>
#include <Render/Command/CommandType.h>
#include <Render/Core/Device.h>
#include <Render/Command/CommandList.h>


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
        const std::vector<ICommandListHandle>& commandLists) = 0;

    virtual void Signal(IFence& fence, i32 frameIndex) = 0;

    virtual NativeObject GetNativeObject() = 0;
  };

  using ICommandQueueHandle = mem::TRef<ICommandQueue>;
}
