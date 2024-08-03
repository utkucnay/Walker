#include <Platforms/DirectX12/Core/DX12Fence.h>
#include <Platforms/DirectX12/Command/DX12CommandQueue.h>
#include <Render/Core/Renderer.h>

namespace wkr::render::dx12
{
  UCommandQueue::UCommandQueue(FCommandQueueDesc& desc)
  {
    ID3D12Device* nDevice = (ID3D12Device*)URenderer::GetDefaultDevice().GetNativeHandle();
  }

  UCommandQueue::~UCommandQueue()
  {
    m_commandQueue->Release();
  }

  void UCommandQueue::ExecuteCommandList(
        const std::vector<ICommandList*>& commandLists)
  {
    std::vector<ID3D12CommandList*> nCommandLists;
    std::transform(commandLists.begin(), commandLists.end(),
        std::back_inserter(nCommandLists), [] (auto commandList)
        {
          return static_cast<ID3D12CommandList*>(commandList->GetNativeHandle());
        });
    m_commandQueue->ExecuteCommandLists(nCommandLists.size(), &nCommandLists[0]);
  }

  void UCommandQueue::Signal(IFence& fence, i32 frameIndex)
  {
    auto dxFence = static_cast<UFence*>(&fence);
    auto nFence = static_cast<ID3D12Fence*>(fence.GetNativeHandle(frameIndex));

    HRESULT hr = m_commandQueue->Signal(nFence, dxFence->m_fenceValue[frameIndex]);
    WKR_CORE_ERROR_COND(FAILED(hr), "Fence Signal Error in Command Queue");
  }
}
