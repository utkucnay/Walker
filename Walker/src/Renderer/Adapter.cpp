#include <Render/Adapter.h>

#include <Platforms/DirectX12/DX12.h>
#include <Render/RendererAPI.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  std::vector<Ref<Adapter>> Adapter::GetAllAdapters()
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        DX12Adapter::GetAllAdapters())
    END_RENDERERAPI_CREATE()

    std::vector<Ref<Adapter>> ret;
    return ret;
  }
}
