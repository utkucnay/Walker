#pragma once

#include <Render/PipelineState.h>
#include <Render/Device.h>

namespace wkr::render
{
  class Device;

  enum class CommandListType {
    Direct        = 0,
    Bundle        = 1,
    Compute       = 2,
    Copy          = 3,
    VideoDecode   = 4,
    VideoProcess  = 5,
    VideoEncode   = 6,
    None          = 7
  };

  enum class CommandQueueFlags
  {
    None              = 0,
    DisableGPUTimeout = 0x1
  };

  enum class CommandQueuePriority
  {
    Normal   = 0,
    High     = 100,
    Realtime = 10000
  };

  struct CommandQueueDesc
  {
    CommandListType       listType;
    CommandQueuePriority  priority;
    CommandQueueFlags     flags;
  };

  class CommandAllocator
  {
  public:
    virtual void* GetNativeHandle() = 0;

  public:
    CommandListType type;

  public:
    static Ref<CommandAllocator> Create(
        Ref<Device> device,
        CommandListType listType);
  };

  class CommandList
  {
  public:
    virtual void* GetNativeHandle();

  public:
    static Ref<CommandList> Create(
          Ref<Device> device,
          Ref<CommandAllocator> commandAllocator);

    static Ref<CommandList> Create(
          Ref<Device> device,
          Ref<CommandAllocator> commandAllocator,
          Ref<PipelineState> pipelineState);
  };

  class CommandQueue
  {
  public:
    virtual void* GetNativeHandle() = 0;

  public:
    static Ref<CommandQueue> Create(
      Ref<Device> device,
      CommandQueueDesc& desc);
  };
}
