#include <Platforms/DirectX12/DX12CommandQueue.h>

namespace wkr::render
{
  DX12CommandQueue::DX12CommandQueue(
      mem::Visitor<Device> device,
      const CommandQueueDesc& desc)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();
    D3D12_COMMAND_QUEUE_DESC nDesc = {};

    nDesc.Type      = static_cast<D3D12_COMMAND_LIST_TYPE>(desc.m_commandListType);
    nDesc.Priority  = static_cast<INT>(desc.m_commandQueuePriority);
    nDesc.Flags     = static_cast<D3D12_COMMAND_QUEUE_FLAGS>(desc.m_commandQueueFlags);

    HRESULT hr = nDevice->CreateCommandQueue(&nDesc, IID_PPV_ARGS(&commandQueue));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Queue");
  }

  DX12CommandQueue::~DX12CommandQueue()
  {
    commandQueue->Release();
  }
}
