#pragma once

#include <Render/Command/CommandList.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandList : public CommandList
  {
  public:
    DX12CommandList(CommandListBuilder*  clb);
    ~DX12CommandList() override;

  public:
    void Reset(
        CommandAllocator* commandAllocator,
        PipelineState* pipelineState) override final;

    void* GetNativeHandle() override final { return m_commandList; }

    CommandList::Type GetType() override final;

    void ResourceBarriers(
        std::vector<rsc::bar::ResourceBarrier*> barriers) override final;

    void OMSetRenderTargets(
        std::vector<view::RenderTargetView*> rtvs) override final;

    void ClearRenderTargetView(
        view::RenderTargetView* rtv,
        Color32 color) override final;

    void Close() override final;

  private:
    ID3D12GraphicsCommandList* m_commandList;
  };
}
