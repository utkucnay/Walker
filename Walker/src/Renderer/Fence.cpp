#include <Render/Fence.h>

#include <Render/RendererAPI.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  FenceBuilder* FenceBuilder::SetFenceFlag(Fence::Flag fenceFlag)
  {
    m_fenceFlag = fenceFlag;
    return this;
  }

  Fence* FenceBuilder::BuildRaw(mem::Ref<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRaw(device, m_fenceFlag);
  }

  mem::Ref<Fence> FenceBuilder::BuildRef(mem::Ref<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRef(device, m_fenceFlag);
  }

  mem::Scope<Fence> FenceBuilder::BuildScope(mem::Ref<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryScope(device, m_fenceFlag);
  }

  Fence* FenceFactory::CreateFactoryRaw(
      mem::Ref<Device> device,
      Fence::Flag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Fence(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Ref<Fence> FenceFactory::CreateFactoryRef(
      mem::Ref<Device> device,
      Fence::Flag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12Fence>::Create(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Scope<Fence> FenceFactory::CreateFactoryScope(
      mem::Ref<Device> device,
      Fence::Flag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12Fence>::Create(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
