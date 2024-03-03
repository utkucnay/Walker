#pragma once

#include <Render/Core/PipelineState.h>
#include <Render/Core/Device.h>

#define COMMAND_INCLUDE_BARRIER

namespace wkr::render
{
  class Device;
  class CommandAllocator;

  class CommandListBuilder;

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
    CommandList(mem::Visitor<CommandListBuilder> clb);
    virtual ~CommandList() = 0;

  public:
    CommandList::Type GetType() const { return m_type; }

  public:
    virtual void* GetNativeHandle() = 0;

  protected:
    CommandList::Type m_type;
  };

  class CommandListBuilder : Builder<CommandList, mem::Visitor<Device>>
  {
  public:
    CommandListBuilder& SetCommandListType(CommandList::Type listType);
    CommandListBuilder& SetCommandAllocator(CommandAllocator* alloc);
    CommandListBuilder& SetPiplineState(PipelineState* pipelineState);

    std::tuple<CommandAllocator*, PipelineState*> GetPointers() const
    {
      return {m_commandAllocator, m_piplelineState};
    }

  public:
    CommandList* BuildRaw(
        mem::Visitor<Device> device) override final;
    mem::Ref<CommandList> BuildRef(
        mem::Visitor<Device> device) override final;
    mem::Scope<CommandList> BuildScope(
        mem::Visitor<Device> device) override final;

  private:
    CommandList::Type         m_listType{};
    CommandAllocator*         m_commandAllocator{};
    PipelineState*            m_piplelineState{};

    friend class CommandList;
  };

  class CommandListFactory : Factory<
                                    CommandList,
                                    mem::Visitor<Device>,
                                    mem::Visitor<CommandListBuilder>>
  {
  public:
    CommandList*            CreateFactoryRaw  (
        mem::Visitor<Device>              device,
        mem::Visitor<CommandListBuilder>  clb) override final;

    mem::Ref<CommandList>   CreateFactoryRef  (
        mem::Visitor<Device>            device,
        mem::Visitor<CommandListBuilder>  clb) override final;

    mem::Scope<CommandList> CreateFactoryScope(
        mem::Visitor<Device>            device,
        mem::Visitor<CommandListBuilder>  clb) override final;
  };
}
