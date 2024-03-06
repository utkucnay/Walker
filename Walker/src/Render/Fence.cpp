#include <Render/Core/Fence.h>

#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  FenceBuilder* FenceBuilder::SetFenceFlag(Fence::Flag fenceFlag)
  {
    m_fenceFlag = fenceFlag;
    return this;
  }

  Fence* FenceBuilder::BuildRaw(Device* device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRaw(device, this);
  }

  mem::Ref<Fence> FenceBuilder::BuildRef(Device* device)
  {
     return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryRef(device, this);
  }

  mem::Scope<Fence> FenceBuilder::BuildScope(Device* device)
  {
    return mem::Scope<FenceFactory>::Create()
      ->CreateFactoryScope(device, this);
  }
}
