#pragma once

#include <Render/Core/PipelineState.h>
#include <Render/Core/Device.h>
#include <Render/ResourceView/RenderTargetView.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

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
    virtual ~CommandList() = 0;

  public:
    virtual CommandList::Type GetType() = 0;

  public:
    virtual void ResourceBarriers(
        std::vector<rsc::bar::ResourceBarrier*> barriers) = 0;

    virtual void OMSetRenderTargets(
        std::vector<view::RenderTargetView*> rtvs) = 0;

    virtual void ClearRenderTargetView(
        view::RenderTargetView* rtv,
        Color32 color) = 0;

    virtual void Close() = 0;

    virtual void* GetNativeHandle() = 0;
  };

  class CommandListBuilder : Builder<CommandList>
  {
  public:
    CommandListBuilder& SetCommandListType(CommandList::Type listType);
    CommandListBuilder& SetCommandAllocator(CommandAllocator* alloc);
    CommandListBuilder& SetPiplineState(PipelineState* pipelineState);

  public:
    CommandList* BuildRaw() override final;
    mem::Ref<CommandList> BuildRef() override final;
    mem::Scope<CommandList> BuildScope() override final;

  public:
    Device*                   m_device;
    CommandList::Type         m_listType{};
    CommandAllocator*         m_commandAllocator{};
    PipelineState*            m_piplelineState{};
  };
}
