#include "Platforms/DirectX12/Command/DX12CommandQueue.h"
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12Fence.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::render::dx12 {

UCommandQueue::UCommandQueue(FCommandQueueDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  D3D12_COMMAND_QUEUE_DESC nDesc = {};
  nDesc.Type = ConvertECommandType(desc.m_commandType);
  nDesc.Priority = static_cast<INT>(desc.m_commandQueuePriority);
  nDesc.Flags = ConvertECommandQueueFlags(desc.m_commandQueueFlags);

  HRESULT hr =
      nDevice->CreateCommandQueue(&nDesc, IID_PPV_ARGS(&m_commandQueue));

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command Queue");
  WKR_CORE_LOG("Created DX12 Command Queue");
}

UCommandQueue::~UCommandQueue() {
  m_commandQueue->Release();
}

void UCommandQueue::ExecuteCommandList(
    const std::vector<ICommandList*>& commandLists) {
  std::vector<ID3D12CommandList*> nCommandLists;
  std::transform(commandLists.begin(), commandLists.end(),
                 std::back_inserter(nCommandLists), [](auto commandList) {
                   return commandList->GetNativeObject();
                 });
  m_commandQueue->ExecuteCommandLists(nCommandLists.size(), &nCommandLists[0]);
}

void UCommandQueue::Signal(IFence& fence, i32 frameIndex) {
  auto dxFence = static_cast<UFence*>(&fence);

  HRESULT hr = m_commandQueue->Signal(fence.GetNativeObject(frameIndex),
                                      dxFence->m_fenceValue[frameIndex]);

  WKR_CORE_ERROR_COND(FAILED(hr), "Fence Signal Error in Command Queue");
}

}  // namespace wkr::render::dx12
