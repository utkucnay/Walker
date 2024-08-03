#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Buffers.h>

namespace wkr::render::dx12
{
  UBuffers::UBuffers(FBuffersDesc& desc)
  {
    auto nDevice = URenderer::GetDefaultDevice().GetNativeObject();
  }

  UBuffers::~UBuffers()
  {
    m_resource->Release();
  }
}
