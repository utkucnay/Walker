#include "Graphics/Core/UGraphicsAPI.h"

#if defined(WKR_PLATFORM_DIRECTX12)
#include "Platforms/DirectX12/Core/DX12AbstractFactory.h"
#endif

namespace wkr::render {

void UGraphicsAPI::Init(EType apiType) {
  switch (apiType) {
    case UGraphicsAPI::EType::None: {

    } break;

#if defined(WKR_PLATFORM_DIRECTX12)
    case UGraphicsAPI::EType::DirectX12: {
      s_abstractFactory = mem::TScope<dx12::UGraphicsAbstractFactory>::Create();
    } break;
#endif
    default: {

    } break;
  }
}

void UGraphicsAPI::ChangeAPI(EType type) {}

}  // namespace wkr::render
