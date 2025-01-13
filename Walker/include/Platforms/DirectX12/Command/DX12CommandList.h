#pragma once

#include "Graphics/RHI/Command/ICommandList.h"
#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"

namespace wkr::graphics::rhi::dx12 {

class UCommandList : public ICommandList {
 public:
  explicit UCommandList(const FCommandListDesc& desc);
  ~UCommandList() override;

 public:
  void Reset(ICommandAllocator& commandAllocator,
             IPipelineState* pipelineState) override final;

  NativeObject GetNativeObject() override final { return m_commandList; }

  ECommandType GetType() override final;

  void ResourceBarriers(size_t size,
                        IResourceBarrier* const* barrier) override final;

  void OMSetRenderTargets(size_t size,
                          URenderTargetView const* rtvs) override final;

  void ClearRenderTargetView(URenderTargetView& rtv,
                             FColor32 color) override final;

  void CopyResource(IResource& dstResource,
                    IResource& srcResource) override final;

  void Close() override final;

 private:
  ID3D12GraphicsCommandList* m_commandList;
};

}  // namespace wkr::graphics::rhi::dx12
