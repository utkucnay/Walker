#pragma once

#include <Platforms/DirectX12/DX12.h>

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
    static void Init(APIType apiType)
    {
      s_Api = apiType;
    }

    static APIType GetAPI() { return s_Api; }
    //TODO(utku): ChangeAPI at Runtime
    static void ChangeAPI(APIType type) { s_Api = type; }

  private:
    static inline APIType s_Api;
  };
}
