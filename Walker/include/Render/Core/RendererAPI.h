#pragma once

#include <Render/Core/AbstractFactory.h>
#include <Platforms/DirectX12/DX12.h>
#include <Render/Core/RendererMakro.h>

#include<Platforms/DirectX12/Core/DX12AbstractFactory.h>

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

      switch (s_Api)
      {
        case APIType::None:
          {
          } break;
#if defined (WKR_PLATFORM_DIRECTX12)
        case APIType::DirectX12:
          {
            s_abstractFactory = mem::Scope<DX12AbstractFactory>::Create();
          }
#endif
        default:
          {
          } break;
      }
    }

    static APIType GetAPI() { return s_Api; }
    static AbstractFactory* GetAbstractFactory()
    { return s_abstractFactory.Get(); }
    //TODO(utku): ChangeAPI at Runtime
    static void ChangeAPI(APIType type) { s_Api = type; }

  private:
    static inline APIType s_Api;
    static inline mem::Scope<AbstractFactory> s_abstractFactory;
  };
}
