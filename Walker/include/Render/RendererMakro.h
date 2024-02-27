#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/RendererAPI.h>

#define BEGIN_RENDERERAPI_CREATE() \
  switch (RendererAPI::GetAPI()) \
  { \
    case RendererAPI::APIType::None: \
      WKR_CORE_LOG("Renderer API not Be None"); \
      break;

#define END_RENDERERAPI_CREATE() \
    default: \
      WKR_CORE_LOG("Renderer API Undifened"); \
      break; \
  }

#if defined(WKR_PLATFORM_DIRECTX12)
  #define ADD_RENDERERAPI_DIRECTX12_CREATE(CreationFunc, ...) \
    case RendererAPI::APIType::DirectX12: \
      __VA_ARGS__ \
      return CreationFunc; \
      break;
#else
  #define ADD_RENDERERAPI_DIRECTX12_CREATE(CreationFunc, ...)
#endif
