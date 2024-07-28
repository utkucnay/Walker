#pragma once

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
    static void Init(APIType apiType);

    static APIType GetAPI() { return s_Api; }

    [[nodiscard]] static AbstractFactory& GetAbstractFactory()
    { return s_abstractFactory.Get(); }

    //TODO(utku): ChangeAPI at Runtime
    static void ChangeAPI(APIType type) { s_Api = type; }

  private:
    static inline APIType s_Api;
    static inline mem::Scope<AbstractFactory> s_abstractFactory;
  };
}
