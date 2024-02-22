#pragma once

#include <Core/Factory.h>

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
  };

  class CommandAllocatorFactory : Factory<
                                    CommandAllocator,
                                    Ref<Device>,
                                    CommandListType>
  {
  public:
    CommandAllocator*        CreateFactoryRaw  (
        Ref<Device> device,
        CommandListType listType) override;

    Ref<CommandAllocator>    CreateFactoryRef  (
        Ref<Device> device,
        CommandListType listType) override;

    Scope<CommandAllocator>  CreateFactoryScope(
        Ref<Device> device,
        CommandListType listType) override;
  };

  class CommandList
  {
  public:
    virtual void* GetNativeHandle();
  };

  class CommandListFactory : Factory<
                                    CommandList,
                                    Ref<Device>,
                                    Ref<CommandAllocator>,
                                    Ref<PipelineState>>
  {
  public:
    CommandList*        CreateFactoryRaw  (
        Ref<Device>           device,
        Ref<CommandAllocator> allocator,
        Ref<PipelineState>    pipelineState = NULL) override;

    Ref<CommandList>    CreateFactoryRef  (
        Ref<Device>           device,
        Ref<CommandAllocator> allocator,
        Ref<PipelineState>    pipelineState = NULL) override;

    Scope<CommandList>  CreateFactoryScope(
        Ref<Device>           device,
        Ref<CommandAllocator> allocator,
        Ref<PipelineState>    pipelineState = NULL) override;
  };

  class CommandQueue
  {
  public:
    virtual void* GetNativeHandle() = 0;
  };

  class CommandQueueFactory : Factory<
                                    CommandQueue,
                                    Ref<Device>,
                                    CommandQueueDesc&>
  {
  public:
    CommandQueue*       CreateFactoryRaw   (
        Ref<Device>           device,
        CommandQueueDesc& desc) override;

    Ref<CommandQueue>    CreateFactoryRef  (
        Ref<Device>           device,
        CommandQueueDesc& desc) override;

    Scope<CommandQueue>  CreateFactoryScope(
        Ref<Device>           device,
        CommandQueueDesc& desc) override;
  };
}
