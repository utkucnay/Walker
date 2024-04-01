#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Buffers.h>

namespace wkr::render::rsc
{
  DX12Buffers::DX12Buffers(ResourceBuilder<Buffers>* rb)
  {
    auto nDevice = static_cast<ID3D12Device*>(Renderer::GetDefaultDevice()->GetNativeHandle());


  }
}
