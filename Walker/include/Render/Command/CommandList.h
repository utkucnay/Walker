#pragma once

#include <Render/Core/PipelineState.h>
#include <Render/Core/Device.h>
#include <Render/ResourceView/RenderTargetView.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>
#include <Render/Command/CommandType.h>

namespace wkr::render
{
  class ICommandAllocator;

  struct FCommandListDesc
  {
    ECommandType                        m_commandType;
    mem::TWeakRef<ICommandAllocator>    m_commandAllocator;
    mem::TWeakRef<IPipelineState>       m_pipelineState;
  };

  class ICommandList
  {
  public:
    virtual ~ICommandList() {}

  public:
    virtual ECommandType GetType() = 0;

  public:
    virtual void Reset(
        ICommandAllocator& commandAllocator) = 0;

    virtual void Reset(
        ICommandAllocator& commandAllocator,
        IPipelineState& pipelineState) = 0;

    virtual void ResourceBarriers(
        const std::vector<mem::TRef<rsc::bar::IResourceBarrier>>& barriers) = 0;

    virtual void OMSetRenderTargets(
        const std::vector<mem::TRef<view::URenderTargetView>>& rtvs) = 0;

    virtual void ClearRenderTargetView(
        view::URenderTargetView& rtv,
        FColor32 color) = 0;

  //  virtual void CopyBufferRegion(
  //      rsc::Buffers dstBuffers, uint64_t dstOffset,
  //      rsc::Buffers srcBuffers, uint64_t srcOffset,
  //      uint64_t numBytes) = 0;

    virtual void CopyResource(
        rsc::IResource& dstResource,
        rsc::IResource& srcResource) = 0;

    virtual void Close() = 0;

    virtual NativeObject GetNativeObject() = 0;
  };

  using ICommandListHandle = mem::TRef<ICommandList>;
}
