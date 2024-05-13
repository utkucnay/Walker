#pragma once

#include <Render/Command/CommandList.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12CommandList : public ICommandList
  {
  public:
    UDX12CommandList(CommandListBuilder& clb);
    ~UDX12CommandList() override;

  public:
    void Reset(
        ICommandAllocator& commandAllocator) override final;

    void Reset(
        ICommandAllocator& commandAllocator,
        IPipelineState& pipelineState) override final;

    NativeHandle GetNativeHandle() override final { return m_commandList; }

    ICommandList::Type GetType() override final;

    void ResourceBarriers(
        const std::vector<mem::Ref<rsc::bar::IResourceBarrier>>& barriers) override final;

    void OMSetRenderTargets(
        const std::vector<mem::Ref<view::URenderTargetView>>& rtvs) override final;

    void ClearRenderTargetView(
        view::URenderTargetView& rtv,
        Color32 color) override final;

    void CopyResource(
        rsc::IResource& dstResource,
        rsc::IResource& srcResource) override final;

    void Close() override final;

  private:
    ID3D12GraphicsCommandList* m_commandList;
  };
}
