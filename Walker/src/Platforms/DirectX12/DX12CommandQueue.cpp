#include <Platforms/DirectX12/Core/DX12Fence.h>
#include <Platforms/DirectX12/Command/DX12CommandQueue.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  DX12CommandQueue::DX12CommandQueue(CommandQueueBuilder* cqb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)Renderer::GetDefaultDevice()->GetNativeHandle();
    D3D12_COMMAND_QUEUE_DESC nDesc = {};

    nDesc.Type      = static_cast<D3D12_COMMAND_LIST_TYPE>(cqb->m_commandListType);
    nDesc.Priority  = static_cast<INT>(cqb->m_commandQueuePriority);
    nDesc.Flags     = static_cast<D3D12_COMMAND_QUEUE_FLAGS>(cqb->m_commandQueueFlags);

    HRESULT hr = nDevice->CreateCommandQueue(&nDesc, IID_PPV_ARGS(&m_commandQueue));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Queue")
    WKR_CORE_LOG("Created DX12 Command Queue")
  }

  DX12CommandQueue::~DX12CommandQueue()
  {
    m_commandQueue->Release();
  }

  void DX12CommandQueue::ExecuteCommandList(std::vector<CommandList*> commandLists)
  {
    std::vector<ID3D12CommandList*> nCommandLists;
    std::transform(commandLists.begin(), commandLists.end(),
        std::back_inserter(nCommandLists), [] (auto commandList)
        {
          return static_cast<ID3D12CommandList*>(commandList->GetNativeHandle());
        });
    m_commandQueue->ExecuteCommandLists(nCommandLists.size(), &nCommandLists[0]);
  }

  void DX12CommandQueue::Signal(Fence* fence, int frameIndex)
  {
    auto dxFence = static_cast<DX12Fence*>(fence);
    auto nFence = static_cast<ID3D12Fence*>(fence->GetNativeHandle(frameIndex));

    HRESULT hr = m_commandQueue->Signal(nFence, dxFence->m_fenceValue[frameIndex]);
    WKR_CORE_ERROR_COND(FAILED(hr), "Fence Signal Error in Command Queue");
  }
}
