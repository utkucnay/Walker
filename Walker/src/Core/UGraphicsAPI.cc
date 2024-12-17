#include "Graphics/Core/UGraphicsAPI.h"

#if defined(WKR_PLATFORM_DIRECTX12)
#include "Platforms/DirectX12/Factory/DX12AbstractFactory.h"
#endif

namespace wkr::graphics {

void UGraphicsAPI::Init(EType apiType) {
  switch (apiType) {
    case UGraphicsAPI::EType::None: {

    } break;

#if defined(WKR_PLATFORM_DIRECTX12)
    case UGraphicsAPI::EType::DirectX12: {
      s_abstractFactory = mem::TScope<rhi::dx12::URHIAbstractFactory>::Create();
    } break;
#endif
    default: {

    } break;
  }
}

void UGraphicsAPI::ChangeAPI(EType type) {}

}  // namespace wkr::render
