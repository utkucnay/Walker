#pragma once

namespace wkr::graphics::rhi::dx12 {

class UDX12Factory {
 public:
  static void Init() {

    WKR_DX12_DEBUG_INIT();
    HRESULT hr = CreateDXGIFactory1(IID_PPV_ARGS(&m_DxgiFactory));

    if (FAILED(hr)) {
      WKR_CORE_WARNING("Didn't Create DXGIFactory");
    }

    WKR_CORE_LOG("DXGI Factory Created");

  }

  static void Destroy() {
    m_DxgiFactory->Release();
    WKR_DX12_DEBUG_DESTROY();
    WKR_CORE_LOG("DXGI Factory Destroyed");
  }

  static IDXGIFactory4* GetFactory() { return m_DxgiFactory; }

 private:
  static inline IDXGIFactory4* m_DxgiFactory = nullptr;
};

}  // namespace wkr::graphics::rhi::dx12
