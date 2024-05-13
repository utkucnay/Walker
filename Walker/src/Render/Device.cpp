#include <Render/Core/Device.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  DeviceBuilder& DeviceBuilder::SetAdapter(
      mem::WeakRef<IAdapter> adapter)
  {
    m_adapter = adapter;
    return *this;
  }

  IDevice* DeviceBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetDeviceFactory()
      ->CreateRaw(*this);
  }

  mem::Ref<IDevice> DeviceBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetDeviceFactory()
      ->CreateRef(*this);
  }

  mem::Scope<IDevice> DeviceBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetDeviceFactory()
      ->CreateScope(*this);
  }
}
