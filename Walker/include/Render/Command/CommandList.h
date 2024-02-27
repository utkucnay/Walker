#pragma once

#include <Render/PipelineState.h>
#include <Render/Device.h>

#define COMMAND_INCLUDE_BARRIER

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
    virtual void* GetNativeHandle() = 0;
  };

  class CommandListBuilder : Builder<CommandList, mem::Visitor<Device>>
  {
  public:
    CommandListBuilder& SetCommandListType(CommandList::Type listType);
    CommandListBuilder& SetCommandAllocator(CommandAllocator* alloc);
    CommandListBuilder& SetPiplineState(PipelineState* pipelineState);

  public:
    CommandList* BuildRaw(
        mem::Visitor<Device> device) override;
    mem::Ref<CommandList> BuildRef(
        mem::Visitor<Device> device) override;
    mem::Scope<CommandList> BuildScope(
        mem::Visitor<Device> device) override;

  private:
    CommandList::Type         m_listType;
    CommandAllocator*         m_commandAllocator = {};
    PipelineState*            m_piplelineState = {};
  };

  class CommandListFactory : Factory<
                                    CommandList,
                                    mem::Visitor<Device>,
                                    CommandList::Type,
                                    mem::Visitor<CommandAllocator>,
                                    PipelineState*>
  {
  public:
    CommandList*            CreateFactoryRaw  (
        mem::Visitor<Device>            device,
        CommandList::Type               listType,
        mem::Visitor<CommandAllocator>  allocator,
        PipelineState*        pipelineState = NULL) override;

    mem::Ref<CommandList>   CreateFactoryRef  (
        mem::Visitor<Device>            device,
        CommandList::Type               listType,
        mem::Visitor<CommandAllocator>  allocator,
        PipelineState*        pipelineState = NULL) override;

    mem::Scope<CommandList> CreateFactoryScope(
        mem::Visitor<Device>            device,
        CommandList::Type               listType,
        mem::Visitor<CommandAllocator>  allocator,
        PipelineState*    pipelineState = NULL) override;
  };
}
