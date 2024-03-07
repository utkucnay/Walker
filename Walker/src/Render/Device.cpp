#include <Render/Core/Device.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  DeviceBuilder& DeviceBuilder::SetAdapter(Adapter* adapter)
  {
    m_adapter = adapter;
    return *this;
  }

  Device* DeviceBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetDeviceFactory()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<Device> DeviceBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetDeviceFactory()
      ->CreateFactoryRef(this);
  }

  mem::Scope<Device> DeviceBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetDeviceFactory()
      ->CreateFactoryScope(this);
  }
}
