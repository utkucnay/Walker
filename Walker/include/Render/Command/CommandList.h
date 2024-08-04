#pragma once

#include <Render/Command/CommandTypes.h>
#include <Render/Command/commandAllocator.h>
#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>
#include <Render/Core/PipelineState.h>
#include <Render/ResourceView/RenderTargetView.h>

namespace wkr::render
{
  struct FCommandListDesc
  {
    ECommandType            m_commandType;
    IPipelineState*         m_pipelineState;
    ICommandAllocatorHandle m_commandAllocator;
  };

  class ICommandList
  {
  public:
    virtual ~ICommandList() = default;

  public:
    virtual ECommandType GetType() = 0;

  public:
    virtual void Reset(
        ICommandAllocator& commandAllocator,
        IPipelineState* pipelineState) = 0;

    virtual void ResourceBarriers(
        const std::vector<IResourceBarrier*>& barriers) = 0;

    virtual void OMSetRenderTargets(
        const std::vector<ARenderTargetView*>& rtvs) = 0;

    virtual void ClearRenderTargetView(
        ARenderTargetView& rtv,
        FColor32 color) = 0;

  //  virtual void CopyBufferRegion(
  //      rsc::Buffers dstBuffers, uint64_t dstOffset,
  //      rsc::Buffers srcBuffers, uint64_t srcOffset,
  //      uint64_t numBytes) = 0;

    virtual void CopyResource(
        IResource& dstResource,
        IResource& srcResource) = 0;

    virtual void Close() = 0;

    virtual NativeObject GetNativeObject() = 0;
  };

  using ICommandListHandle = mem::TRef<ICommandList>;
}
