#include "Core/Base.h"
#include <Platforms/DirectX12/Resource/DX12Resource.h>
#include <Render/Core/Renderer.h>
#include <Platforms/DirectX12/Resource/DX12Buffers.h>

namespace wkr::render::rsc
{
  UDX12Buffers::UDX12Buffers(ResourceBuilder<IBuffers>& rb)
  {
    auto nDevice = static_cast<ID3D12Device*>(URenderer::GetDefaultDevice().GetNativeHandle());
    HRESULT hr;

    CREATE_RESOURCE(rb, m_resource, nDevice, hr);
    WKR_CORE_ERROR_COND(FAILED(hr), "Buffes Not Created!");

    WKR_CORE_LOG("Created DX12 Buffers");
  }

  UDX12Buffers::~UDX12Buffers()
  {
    m_resource->Release();
  }
}
