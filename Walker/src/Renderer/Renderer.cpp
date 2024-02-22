#include <Render/Renderer.h>

#include <Platforms/DirectX12/DX12.h>
#include <Render/RendererMakro.h>
#include <Render/RendererAPI.h>

namespace wkr::render
{
  Renderer* RendererFactory::CreateFactoryRaw(Window* window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Renderer(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<Renderer> RendererFactory::CreateFactoryRef(Window* window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12Renderer>::Create(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Scope<Renderer> RendererFactory::CreateFactoryScope(Window* window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12Renderer>::Create(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
