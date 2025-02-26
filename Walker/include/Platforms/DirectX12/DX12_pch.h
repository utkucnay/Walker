#pragma once

#include "Core/PlatformDetection.h"

#if defined(WKR_PLATFORM_WINDOWS)

#define WKR_PLATFORM_DIRECTX12

#include <d3d12.h>
#include <d3dcompiler.h>
#include <d3dx12/d3dx12.h>
#include <dxgi.h>
#include <dxgi1_4.h>

#include "Platforms/DirectX12/Core/DX12Base.h"

#endif
