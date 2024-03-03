#include <Platforms/DirectX12/DX12RenderTargetView.h>

namespace wkr::render::view
{
  DX12RenderTargetView::DX12RenderTargetView(
        mem::Visitor<Device>                  device,
        mem::Visitor<RenderTargetViewBuilder> rtvb,
        mem::Visitor<SwapChain>               swapChain)
  {
  }

  DX12RenderTargetView::~DX12RenderTargetView()
  {
    m_renderTargetView->Release();
  }
}
