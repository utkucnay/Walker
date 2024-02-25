#pragma once

#include <Core/PlatformDetection.h>

namespace wkr::render
{
  class RendererAPI
  {
  public:
    enum class APIType
    {
      None      = 0,
      DirectX12 = 1
    };

  public:
    static APIType GetAPI() { return s_Api; }
    //TODO(utku): ChangeAPI at Runtime
    static void ChangeAPI(APIType type) { s_Api = type; }

  private:
    static inline APIType s_Api;
  };
}
