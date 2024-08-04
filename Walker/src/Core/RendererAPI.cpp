#include <Render/Core/RendererAPI.h>
#include <Platforms/DirectX12/Core/DX12AbstractFactory.h>

namespace wkr::render
{
  void URendererAPI::Init(EType apiType)
  {
    switch (apiType)
    {
      case URendererAPI::EType::None:
      {

      } break;

      case URendererAPI::EType::DirectX12:
      {
        s_abstractFactory = mem::TScope<dx12::UAbstractFactory>::Create();
      } break;

      default:
      {

      } break;
    }
  }

  void URendererAPI::ChangeAPI(EType type)
  {
  }
}
