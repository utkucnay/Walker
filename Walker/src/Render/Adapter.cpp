#include <Render/Core/Adapter.h>

#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  std::vector<mem::Ref<IAdapter>> IAdapter::GetAllAdapters()
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        UDX12Adapter::GetAllAdapters())
    END_RENDERERAPI_CREATE()

    std::vector<mem::Ref<IAdapter>> ret;
    return ret;
  }
}
