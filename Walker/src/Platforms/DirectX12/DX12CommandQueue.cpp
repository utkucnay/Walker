#include <Platforms/DirectX12/Core/DX12Fence.h>
#include <Platforms/DirectX12/Command/DX12CommandQueue.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  UDX12CommandQueue::UDX12CommandQueue(CommandQueueBuilder& cqb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)URenderer::GetDefaultDevice().GetNativeHandle();
    D3D12_COMMAND_QUEUE_DESC nDesc = {};

    nDesc.Type      = static_cast<D3D12_COMMAND_LIST_TYPE>(cqb.m_commandListType);
    nDesc.Priority  = static_cast<INT>(cqb.m_commandQueuePriority);
    nDesc.Flags     = static_cast<D3D12_COMMAND_QUEUE_FLAGS>(cqb.m_commandQueueFlags);

    HRESULT hr = nDevice->CreateCommandQueue(&nDesc, IID_PPV_ARGS(&m_commandQueue));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Queue")
    WKR_CORE_LOG("Created DX12 Command Queue")
  }

  UDX12CommandQueue::~UDX12CommandQueue()
  {
    m_commandQueue->Release();
  }

  void UDX12CommandQueue::ExecuteCommandList(
        const std::vector<mem::Ref<ICommandList>>& commandLists)
  {
    std::vector<ID3D12CommandList*> nCommandLists;
    std::transform(commandLists.begin(), commandLists.end(),
        std::back_inserter(nCommandLists), [] (auto commandList)
        {
          return static_cast<ID3D12CommandList*>(commandList->GetNativeHandle());
        });
    m_commandQueue->ExecuteCommandLists(nCommandLists.size(), &nCommandLists[0]);
  }

  void UDX12CommandQueue::Signal(IFence& fence, i32 frameIndex)
  {
    auto dxFence = static_cast<UDX12Fence*>(&fence);
    auto nFence = static_cast<ID3D12Fence*>(fence.GetNativeHandle(frameIndex));

    HRESULT hr = m_commandQueue->Signal(nFence, dxFence->m_fenceValue[frameIndex]);
    WKR_CORE_ERROR_COND(FAILED(hr), "Fence Signal Error in Command Queue");
  }
}
