#pragma once

#include "Graphics/Core/GraphicsType.h"
#include "Graphics/RHI/Command/CommandType.h"
#include "Graphics/RHI/Command/ICommandAllocator.h"
#include "Graphics/RHI/Core/IPipelineState.h"
#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/Resource/View/URenderTargetView.h"

namespace wkr::graphics::rhi {

struct WALKER_API FCommandListDesc {
  ECommandType CommandType = ECommandType::kNone;
  IPipelineState* PipelineState = nullptr;
  ICommandAllocatorHandle CommandAllocator = nullptr;
};

class WALKER_API ICommandList {
 public:
  virtual ~ICommandList() = default;

 public:
  virtual ECommandType GetType() = 0;

 public:
  virtual void Reset(ICommandAllocator& commandAllocator,
                     IPipelineState* pipelineState) = 0;

  void ResourceBarriers(
      const std::initializer_list<IResourceBarrier*>& barriers) {
    ResourceBarriers(barriers.size(), barriers.begin());
  }

  virtual void ResourceBarriers(size_t size, IResourceBarrier* const* data) = 0;

  void OMSetRenderTargets(
      const std::initializer_list<URenderTargetView>& rtvs) {
    OMSetRenderTargets(rtvs.size(), rtvs.begin());
  };

  virtual void OMSetRenderTargets(size_t size,
                                  URenderTargetView const* rtvs) = 0;

  virtual void ClearRenderTargetView(URenderTargetView& rtv,
                                     FColor32 color) = 0;

  //  virtual void CopyBufferRegion(
  //      rsc::Buffers dstBuffers, uint64_t dstOffset,
  //      rsc::Buffers srcBuffers, uint64_t srcOffset,
  //      uint64_t numBytes) = 0;

  virtual void CopyResource(IResource& dstResource, IResource& srcResource) = 0;

  virtual void Close() = 0;

  virtual NativeObject GetNativeObject() = 0;
};

using ICommandListHandle = wkr::mem::TRef<ICommandList>;

}  // namespace wkr::graphics::rhi
