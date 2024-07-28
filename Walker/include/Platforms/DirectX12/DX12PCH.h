#pragma once

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #include <d3d12.h>
  #include <d3dx12/d3dx12.h>
  #include <dxgi.h>
  #include <dxgi1_4.h>
  #include <d3dcompiler.h>
#endif
