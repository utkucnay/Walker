#include <Render/RenderMakro.h>
#include <Platforms/DirectX12/DX12Renderer.h>
#include <Render/RendererAPI.h>

namespace wkr::render
{
  Ref<Renderer> Renderer::Create(Window* window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_CREATE(
        RendererAPI::APIType::DirectX12,
        CreateRef<DX12Renderer>(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
