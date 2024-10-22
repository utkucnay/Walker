#pragma once

namespace wkr::render::dx12
{
  class UDX12Factory
  {
    public:
      static void Init()
      {
        HRESULT hr = CreateDXGIFactory1(IID_PPV_ARGS(&m_dxgiFactory));
        WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create DXGIFactory");
      }

      static IDXGIFactory4* GetFactory() { return m_dxgiFactory; }

    private:
      static inline IDXGIFactory4* m_dxgiFactory = NULL;
  };
}
