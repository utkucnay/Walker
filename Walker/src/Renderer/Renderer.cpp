#include <Render/Renderer.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  Renderer::~Renderer()
  {

  }

  Renderer* RendererFactory::CreateFactoryRaw(mem::Ref<Window> window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Renderer(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Ref<Renderer> RendererFactory::CreateFactoryRef(mem::Ref<Window> window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12Renderer>::Create(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Scope<Renderer> RendererFactory::CreateFactoryScope(mem::Ref<Window> window)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12Renderer>::Create(window))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
