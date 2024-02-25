#pragma once

#include <Render/PipelineState.h>
#include <Render/Device.h>

namespace wkr::render
{
  class Device;
  class CommandAllocator;

  class CommandList
  {
  public:
    enum class Type
    {
      Direct        = 0,
      Bundle        = 1,
      Compute       = 2,
      Copy          = 3,
      VideoDecode   = 4,
      VideoProcess  = 5,
      VideoEncode   = 6,
      None          = 7
    };

  public:
    virtual ~CommandList() = 0;

  public:
    virtual void* GetNativeHandle();

  private:
    CommandList::Type listType;
  };

  class CommandListBuilder : Builder<CommandList, mem::Ref<Device>>
  {
  public:
    CommandListBuilder& SetCommandListType  (CommandList::Type listType);
    CommandListBuilder& SetCommandAllocator (mem::Ref<CommandAllocator> alloc);
    CommandListBuilder& SetPiplineState     (mem::Ref<PipelineState> pipelineState);

  public:
    CommandList*            BuildRaw  (mem::Ref<Device> device) override;
    mem::Ref<CommandList>   BuildRef  (mem::Ref<Device> device) override;
    mem::Scope<CommandList> BuildScope(mem::Ref<Device> device) override;

  private:
    CommandList::Type           m_listType;
    mem::Ref<CommandAllocator>  m_commandAllocator;
    mem::Ref<PipelineState>     m_piplelineState;
  };

  class CommandListFactory : Factory<
                                    CommandList,
                                    mem::Ref<Device>,
                                    CommandList::Type,
                                    mem::Ref<CommandAllocator>,
                                    mem::Ref<PipelineState>>
  {
  public:
    CommandList*            CreateFactoryRaw  (
        mem::Ref<Device>           device,
        CommandList::Type     listType,
        mem::Ref<CommandAllocator> allocator,
        mem::Ref<PipelineState>    pipelineState = NULL) override;

    mem::Ref<CommandList>   CreateFactoryRef  (
        mem::Ref<Device>           device,
        CommandList::Type     listType,
        mem::Ref<CommandAllocator> allocator,
        mem::Ref<PipelineState>    pipelineState = NULL) override;

    mem::Scope<CommandList> CreateFactoryScope(
        mem::Ref<Device>           device,
        CommandList::Type     listType,
        mem::Ref<CommandAllocator> allocator,
        mem::Ref<PipelineState>    pipelineState = NULL) override;
  };
}
