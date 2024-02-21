#pragma once

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

#define ADD_RENDERERAPI_CREATE(APIType, CreationFunc, ...) \
    case APIType: \
      __VA_ARGS__ \
      return CreationFunc; \
      break;
