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

  REGISTER_BUILDER(I, Device);
}
