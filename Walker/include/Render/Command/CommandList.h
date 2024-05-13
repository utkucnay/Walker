#pragma once

#include <Render/Core/PipelineState.h>
#include <Render/Core/Device.h>
#include <Render/ResourceView/RenderTargetView.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

#define COMMAND_INCLUDE_BARRIER

namespace wkr::render
{
  class ICommandAllocator;

  class ICommandList
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
    virtual ~ICommandList() {}

  public:
    virtual ICommandList::Type GetType() = 0;

  public:
    virtual void Reset(
        ICommandAllocator& commandAllocator) = 0;

    virtual void Reset(
        ICommandAllocator& commandAllocator,
        IPipelineState& pipelineState) = 0;

    virtual void ResourceBarriers(
        const std::vector<mem::Ref<rsc::bar::IResourceBarrier>>& barriers) = 0;

    virtual void OMSetRenderTargets(
        const std::vector<mem::Ref<view::URenderTargetView>>& rtvs) = 0;

    virtual void ClearRenderTargetView(
        view::URenderTargetView& rtv,
        Color32 color) = 0;

  //  virtual void CopyBufferRegion(
  //      rsc::Buffers dstBuffers, uint64_t dstOffset,
  //      rsc::Buffers srcBuffers, uint64_t srcOffset,
  //      uint64_t numBytes) = 0;

    virtual void CopyResource(
        rsc::IResource& dstResource,
        rsc::IResource& srcResource) = 0;

    virtual void Close() = 0;

    virtual NativeHandle GetNativeHandle() = 0;
  };

  class CommandListBuilder : IBuilder<ICommandList>
  {
  public:
    CommandListBuilder(mem::WeakRef<ICommandAllocator> commandAllocator);

  public:
    CommandListBuilder& SetCommandListType(ICommandList::Type listType);
    CommandListBuilder& SetPiplineState(mem::WeakRef<IPipelineState> pipelineState);

  public:
    [[nodiscard]] ICommandList*              BuildRaw()    override final;
    [[nodiscard]] mem::Ref<ICommandList>     BuildRef()    override final;
    [[nodiscard]] mem::Scope<ICommandList>   BuildScope()  override final;

  public:
    ICommandList::Type               m_listType{};
    mem::WeakRef<ICommandAllocator>  m_commandAllocator{};
    mem::WeakRef<IPipelineState>     m_pipelineState{};
  };
}
