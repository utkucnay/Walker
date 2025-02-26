#pragma once

#if DEBUG

#include "Platforms/DirectX12/Debug/DX12DebugLayer.h"

#define WKR_DX12_DEBUG_INIT() UDebugLayer::Init();
#define WKR_DX12_ERROR(hr) UDebugLayer::Get().LogErrorMessages(hr);
#define WKR_DX12_DEBUG_DESTROY() UDebugLayer::Destroy();
#define WKR_DX12_DEBUG_SET_DEVICE(device) \
  UDebugLayer::Get().SetDX12Device(device);

#else

#define WKR_DX12_DEBUG_INIT()
#define WKR_DX12_ERROR()
#define WKR_DX12_DEBUG_DESTROY()
#define WKR_DX12_DEBUG_SET_DEVICE(device)

#endif
