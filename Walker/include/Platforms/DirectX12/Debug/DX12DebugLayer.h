#pragma once

#include <d3d12sdklayers.h>
#include <dxgidebug.h>

namespace wkr::graphics::rhi::dx12 {

class UDebugLayer {
 public:
  UDebugLayer();
  ~UDebugLayer();

 public:
  void SetDX12Device(ID3D12Device* device);
  void LogErrorMessages(HRESULT hr);

 private:
  ID3D12Debug* m_Debug;
  IDXGIDebug1* m_DxgiDebug;
  IDXGIInfoQueue* m_DxgiInfoQueue;
  ID3D12InfoQueue* m_DX12InfoQueue;
  b64 m_IsStarted = false;

public:
  static void Init() { s_DebugDevice = new UDebugLayer(); }
  static UDebugLayer& Get() { return *s_DebugDevice; }
  static void Destroy() { delete s_DebugDevice; }

 private:
  static inline UDebugLayer* s_DebugDevice = nullptr;
};

}  // namespace wkr::graphics::rhi::dx12
