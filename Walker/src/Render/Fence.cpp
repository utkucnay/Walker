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

  REGISTER_BUILDER(I, Fence);
}
