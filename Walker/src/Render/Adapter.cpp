#include <Render/Core/Adapter.h>

#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  std::vector<mem::Ref<Adapter>> Adapter::GetAllAdapters()
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        DX12Adapter::GetAllAdapters())
    END_RENDERERAPI_CREATE()

    std::vector<mem::Ref<Adapter>> ret;
    return ret;
  }
}
