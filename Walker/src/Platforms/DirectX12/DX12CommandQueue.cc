#include "Platforms/DirectX12/Command/DX12CommandQueue.h"
#include "Graphics/Core/UGraphics.h"
#include "Graphics/RHI/Command/ICommandQueue.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UCommandQueue::UCommandQueue(FCommandQueueDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  D3D12_COMMAND_QUEUE_DESC nDesc = {
      .Type = wkrtodx12::ConvertECommandType(desc.CommandType),
      .Priority =
          wkrtodx12::ConvertECommandQueuePriority(desc.CommandQueuePriority),
      .Flags = wkrtodx12::ConvertECommandQueueF(desc.CommandQueueFlag),
  };

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

void UCommandQueue::Signal(AFence& fence, i32 frameIndex) {
  HRESULT hr = m_commandQueue->Signal(fence.GetNativeObject(frameIndex),
                                      fence.GetFenceValue(frameIndex));

  WKR_CORE_ERROR_COND(FAILED(hr), "Fence Signal Error in Command Queue");
}

FCommandQueueDesc UCommandQueue::GetDesc() {
  D3D12_COMMAND_QUEUE_DESC commandQueueDesc = m_commandQueue->GetDesc();
  FCommandQueueDesc retDesc = {
      .CommandType = dx12towkr::ConvertECommandType(commandQueueDesc.Type),
      .CommandQueuePriority =
          dx12towkr::ConvertECommandQueuePriority(commandQueueDesc.Priority),
      .CommandQueueFlag =
          dx12towkr::ConvertECommandQueueF(commandQueueDesc.Flags),
  };
  return retDesc;
}

}  // namespace wkr::graphics::rhi::dx12
