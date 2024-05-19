#include <Render/Core/RendererAPI.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  //Builder
  CommandAllocatorBuilder& CommandAllocatorBuilder::SetCommandListType(
      ICommandList::Type listType)
  {
    m_listType = listType;
    return *this;
  }

  REGISTER_BUILDER(I, CommandAllocator);
}
