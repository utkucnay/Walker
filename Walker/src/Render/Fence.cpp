#include <Render/Core/Fence.h>

#include <Render/Core/RendererAPI.h>
#include <Render/Core/RendererMakro.h>

namespace wkr::render
{
  Fence::Fence(mem::Visitor<FenceBuilder> fb)
  {
    m_flag = fb->m_fenceFlag;
  }

  Fence::~Fence(){}

  FenceBuilder* FenceBuilder::SetFenceFlag(Fence::Flag fenceFlag)
  {
    m_fenceFlag = fenceFlag;
    return this;
  }

  Fence* FenceBuilder::BuildRaw(mem::Visitor<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRaw(device, this);
  }

  mem::Ref<Fence> FenceBuilder::BuildRef(mem::Visitor<Device> device)
  {
     return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRef(device, this);
  }

  mem::Scope<Fence> FenceBuilder::BuildScope(mem::Visitor<Device> device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryScope(device, this);
  }

  Fence* FenceFactory::CreateFactoryRaw(
      mem::Visitor<Device> device,
      mem::Visitor<FenceBuilder> fb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Fence(device, fb))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Ref<Fence> FenceFactory::CreateFactoryRef(
      mem::Visitor<Device> device,
      mem::Visitor<FenceBuilder> fb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12Fence>::Create(device, fb))
    END_RENDERERAPI_CREATE()

    return NULL;
  }

  mem::Scope<Fence> FenceFactory::CreateFactoryScope(
      mem::Visitor<Device> device,
      mem::Visitor<FenceBuilder> fb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12Fence>::Create(device, fb))
    END_RENDERERAPI_CREATE()

    return NULL;
  }
}
