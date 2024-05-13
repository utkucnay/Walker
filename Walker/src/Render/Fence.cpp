#include <Render/Core/Fence.h>

#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  FenceBuilder& FenceBuilder::SetFenceFlag(IFence::Flag fenceFlag)
  {
    m_fenceFlag = fenceFlag;
    return *this;
  }

  FenceBuilder& FenceBuilder::SetFrameCount(u8 frameCount)
  {
    m_frameCount = frameCount;
    return *this;
  }

  IFence* FenceBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetFenceFactory()
      ->CreateRaw(*this);
  }

  mem::Ref<IFence> FenceBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetFenceFactory()
      ->CreateRef(*this);
  }

  mem::Scope<IFence> FenceBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetFenceFactory()
      ->CreateScope(*this);
  }
}
