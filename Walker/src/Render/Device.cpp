#include <Render/Device.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  Device::~Device()
  {

  }

  Device* DeviceFactory::CreateFactoryRaw(Adapter* adapter)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        (NULL == adapter) ?
          new DX12Device() :
          new DX12Device(mem::Visitor<Adapter>(adapter))
        )
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<Device> DeviceFactory::CreateFactoryRef(Adapter* adapter)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        (NULL == adapter) ?
          mem::Ref<DX12Device>::Create() :
          mem::Ref<DX12Device>::Create(mem::Visitor<Adapter>(adapter))
          )
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<Device> DeviceFactory::CreateFactoryScope(Adapter* adapter)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        (NULL == adapter) ?
          mem::Scope<DX12Device>::Create() :
          mem::Scope<DX12Device>::Create(mem::Visitor<Adapter>(adapter))
          )
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
