#include <Platforms/DirectX12/DX12Adapter.h>
#include <Render/RendererAPI.h>
#include <Render/Adapter.h>

#include <Render/RenderMakro.h>

namespace wkr::render
{
  std::vector<Ref<Adapter>> Adapter::GetAllAdapters()
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        DX12Adapter::GetAllAdapters())
    END_RENDERERAPI_CREATE()
  }

  Ref<Adapter> Adapter::Create()
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        CreateRef<DX12Adapter>())
    END_RENDERERAPI_CREATE()
  }
}
