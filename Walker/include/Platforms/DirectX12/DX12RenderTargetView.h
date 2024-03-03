#pragma once

#include <Render/ResourceView/RenderTargetView.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::view
{
  class DX12RenderTargetView : RenderTargetView
  {
  public:
    DX12RenderTargetView(
        mem::Visitor<Device>                  device,
        mem::Visitor<RenderTargetViewBuilder> rtvb,
        mem::Visitor<SwapChain>               swapChain);
    ~DX12RenderTargetView() override;

  public:
    void* GetNativeHandle() override final { return m_renderTargetView; }

  private:
    ID3D12Resource* m_renderTargetView;
  };
}
