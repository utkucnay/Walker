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

  Fence* FenceBuilder::BuildRaw(mem::Visitor<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRaw(device, m_fenceFlag);
  }

  mem::Ref<Fence> FenceBuilder::BuildRef(mem::Visitor<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRef(device, m_fenceFlag);
  }

  mem::Scope<Fence> FenceBuilder::BuildScope(mem::Visitor<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryScope(device, m_fenceFlag);
  }

  Fence* FenceFactory::CreateFactoryRaw(
      mem::Visitor<Device> device,
      Fence::Flag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Fence(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Ref<Fence> FenceFactory::CreateFactoryRef(
      mem::Visitor<Device> device,
      Fence::Flag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12Fence>::Create(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Scope<Fence> FenceFactory::CreateFactoryScope(
      mem::Visitor<Device> device,
      Fence::Flag fenceFlag)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12Fence>::Create(device, fenceFlag))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
