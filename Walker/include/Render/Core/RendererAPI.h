#pragma once

#include <Render/Core/AbstractFactory.h>

namespace wkr::render
{
  class URendererAPI
  {
  public:
    enum class EType
    {
      None      = 0,
      DirectX12 = 1,
    };

  public:
    static void Init(EType apiType);

    static EType GetAPIType() { return s_Api; }

    static IAbstractFactory& GetAbstractFactory()
    { return s_abstractFactory.Get(); }

    static void ChangeAPI(EType type);

  private:
    static inline EType s_Api;
    static inline mem::TScope<IAbstractFactory> s_abstractFactory;
  };
}
