#include <Render/Fence.h>

#include <Render/RendererAPI.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  Fence* FenceFactory::CreateFactoryRaw(
      Ref<Device> device,
      FenceFlag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Fence(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Ref<Fence> FenceFactory::CreateFactoryRef(
      Ref<Device> device,
      FenceFlag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12Fence>::Create(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  Scope<Fence> FenceFactory::CreateFactoryScope(
      Ref<Device> device,
      FenceFlag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12Fence>::Create(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
