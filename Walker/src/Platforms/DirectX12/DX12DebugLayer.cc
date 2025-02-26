#include "Platforms/DirectX12/Debug/DX12DebugLayer.h"
#include "Core/Base.h"

namespace wkr::graphics::rhi::dx12 {

UDebugLayer::UDebugLayer() {
  HRESULT hr = D3D12GetDebugInterface(IID_PPV_ARGS(&m_Debug));

  if (FAILED(hr)) {
    WKR_CORE_WARNING(
        "Didnt Get DX12 Debug Interface. "
        "Go to Optional Features > Add a feature, and then look for Graphics "
        "Tools.");
    return;
  }
  m_Debug->EnableDebugLayer();

  hr = DXGIGetDebugInterface1(0, IID_PPV_ARGS(&m_DxgiDebug));

  if (FAILED(hr)) {
    WKR_CORE_ERROR_COND(FAILED(hr),
                        "Didnt Get DXGI Debug Interface."
                        "Go to Optional Features > Add a feature, and then "
                        "look for Graphics Tools.");
    return;
  }

  m_DxgiDebug->QueryInterface(IID_PPV_ARGS(&m_DxgiInfoQueue));

  m_IsStarted = true;
}

UDebugLayer::~UDebugLayer() {
  m_Debug->Release();
  m_DxgiDebug->Release();
  m_DxgiInfoQueue->Release();
}

void UDebugLayer::SetDX12Device(ID3D12Device* device) {
  device->QueryInterface(IID_PPV_ARGS(&m_DX12InfoQueue));
}

void UDebugLayer::LogErrorMessages(HRESULT hr) {
  if (!m_IsStarted) {
    WKR_CORE_ERROR("Please Install Graphics Tools.");
  }

  std::stringstream ss;

  ss << "\n";

  u64 messageCount = m_DxgiInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
  for (u64 index = 0; index < messageCount; index++) {
    SIZE_T messageLength = 0;
    HRESULT hr =
        m_DxgiInfoQueue->GetMessage(DXGI_DEBUG_ALL, 0, NULL, &messageLength);
    if (hr == S_FALSE) {
      auto message = (DXGI_INFO_QUEUE_MESSAGE*)malloc(messageLength);
      hr = m_DxgiInfoQueue->GetMessage(DXGI_DEBUG_ALL, 0, message,
                                       &messageLength);

      if (hr == S_OK) {
        ss << index << ". DXGI Error: " << message->pDescription << "\n";

        free(message);
      }
    }
  }

  messageCount = m_DX12InfoQueue->GetNumStoredMessages();
  for (u64 index = 0; index < messageCount; index++) {
    SIZE_T messageLength = 0;
    HRESULT hr = m_DX12InfoQueue->GetMessageA(index, NULL, &messageLength);

    if (hr == S_FALSE) {
      auto message = (D3D12_MESSAGE*)malloc(messageLength);
      HRESULT hr = m_DX12InfoQueue->GetMessageA(index, message, &messageLength);

      if (hr == S_OK) {
        ss << index << ". DX12 Error: " << message->pDescription << "\n";

        free(message);
      }
    }
  }

  LPVOID lpMsgBuf;

  DWORD dwFormat = FormatMessage(
      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
          FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0,
      NULL);

  if (dwFormat != 0) {

    ss << "Error Code: " << (u32)hr << " Description: " << (LPCTSTR)lpMsgBuf;

    LocalFree(lpMsgBuf);
  }

  WKR_CORE_ERROR(ss.str());
}

}  // namespace wkr::graphics::rhi::dx12
