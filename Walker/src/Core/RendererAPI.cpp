#include <Render/Core/RendererAPI.h>

#if defined (WKR_PLATFORM_DIRECTX12)
#include <Platforms/DirectX12/Core/DX12AbstractFactory.h>
#endif

namespace wkr::render
{
  void URendererAPI::Init(EType apiType)
  {
    switch (apiType)
    {
      case URendererAPI::EType::None:
      {

      } break;

#if defined (WKR_PLATFORM_DIRECTX12)
      case URendererAPI::EType::DirectX12:
      {
        s_abstractFactory = mem::TScope<dx12::UAbstractFactory>::Create();
      } break;
#endif
      default:
      {

      } break;
    }
  }

  void URendererAPI::ChangeAPI(EType type)
  {
  }
}
