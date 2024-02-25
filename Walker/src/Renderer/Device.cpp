#include <Render/Device.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  Device::~Device()
  {

  }

  Device* DeviceFactory::CreateFactoryRaw(mem::Ref<Adapter> adapter)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12Device(adapter))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<Device> DeviceFactory::CreateFactoryRef(mem::Ref<Adapter> adapter)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12Device>::Create(adapter))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<Device> DeviceFactory::CreateFactoryScope(mem::Ref<Adapter> adapter)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12Device>::Create(adapter))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
