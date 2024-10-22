#pragma once

#include "Graphics/Command/ICommandList.h"

namespace wkr::render::dx12
{
  class UCommandList : public ICommandList
  {
  public:
    UCommandList(FCommandListDesc& desc);
    ~UCommandList() override;

  public:
    void Reset(
        ICommandAllocator& commandAllocator,
        IPipelineState* pipelineState) override final;

    NativeObject GetNativeObject() override final { return m_commandList; }

    ECommandType GetType() override final;

    void ResourceBarriers(
        const std::vector<IResourceBarrier*>& barriers) override final;

    void OMSetRenderTargets(
        const std::vector<wkr::render::ARenderTargetView*>& rtvs) override final;

    void ClearRenderTargetView(
        wkr::render::ARenderTargetView& rtv,
        FColor32 color) override final;

    void CopyResource(
        IResource& dstResource,
        IResource& srcResource) override final;

    void Close() override final;

  private:
    ID3D12GraphicsCommandList* m_commandList;
  };
}
