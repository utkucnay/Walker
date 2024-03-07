#include <Render/Core/Fence.h>

#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  FenceBuilder* FenceBuilder::SetFenceFlag(Fence::Flag fenceFlag)
  {
    m_fenceFlag = fenceFlag;
    return this;
  }

  Fence* FenceBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetFenceFactory()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<Fence> FenceBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetFenceFactory()
      ->CreateFactoryRef(this);
  }

  mem::Scope<Fence> FenceBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetFenceFactory()
      ->CreateFactoryScope(this);
  }
}
