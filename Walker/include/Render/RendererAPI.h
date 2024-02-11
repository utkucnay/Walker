#pragma once

#include <Core/PlatformDetection.h>

namespace wkr::render
{
  class RendererAPI
  {
  public:
    enum class APIType
    {
      None = 0,
    #if defined (WKR_PLATFORM_WINDOWS)
      DirectX12 = 1
    #endif
    };

  public:
    static APIType GetAPI() { return s_Api; };
    //TODO(utku): ChangeAPI at Runtime
    static void ChangeAPI(APIType type);

  private:
    static APIType s_Api;
  };
}
