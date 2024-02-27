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

  class CommandListBuilder : Builder<CommandList, Device*>
  {
  public:
    CommandListBuilder& SetCommandListType  (CommandList::Type listType);
    CommandListBuilder& SetCommandAllocator (CommandAllocator* alloc);
    CommandListBuilder& SetPiplineState     (PipelineState* pipelineState);

  public:
    CommandList*            BuildRaw  (Device* device) override;
    mem::Ref<CommandList>   BuildRef  (Device* device) override;
    mem::Scope<CommandList> BuildScope(Device* device) override;

  private:
    CommandList::Type           m_listType;
    CommandAllocator*           m_commandAllocator;
    PipelineState*              m_piplelineState;
  };

  class CommandListFactory : Factory<
                                    CommandList,
                                    Device*,
                                    CommandList::Type,
                                    CommandAllocator*,
                                    PipelineState*>
  {
  public:
    CommandList*            CreateFactoryRaw  (
        Device*               device,
        CommandList::Type     listType,
        CommandAllocator*     allocator,
        PipelineState*        pipelineState = NULL) override;

    mem::Ref<CommandList>   CreateFactoryRef  (
        Device*               device,
        CommandList::Type     listType,
        CommandAllocator*     allocator,
        PipelineState*        pipelineState = NULL) override;

    mem::Scope<CommandList> CreateFactoryScope(
        Device*           device,
        CommandList::Type listType,
        CommandAllocator* allocator,
        PipelineState*    pipelineState = NULL) override;
  };
}
