#include <Platforms/DirectX12/DX12CommandQueue.h>

namespace wkr::render
{
  DX12CommandQueue::DX12CommandQueue(
      mem::Visitor<Device> device,
        CommandList::Type       commandType,
        CommandQueue::Priority  queuePriorty,
        CommandQueue::Flags     flags) :
    CommandQueue(commandType, queuePriorty, flags)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();
    D3D12_COMMAND_QUEUE_DESC nDesc = {};

    nDesc.Type      = static_cast<D3D12_COMMAND_LIST_TYPE>(m_listType);
    nDesc.Priority  = static_cast<INT>(m_priority);
    nDesc.Flags     = static_cast<D3D12_COMMAND_QUEUE_FLAGS>(m_flags);

    HRESULT hr = nDevice->CreateCommandQueue(&nDesc, IID_PPV_ARGS(&m_commandQueue));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Queue")
    WKR_CORE_LOG("Created DX12 Command Queue")
  }

  DX12CommandQueue::~DX12CommandQueue()
  {
    m_commandQueue->Release();
  }
}
