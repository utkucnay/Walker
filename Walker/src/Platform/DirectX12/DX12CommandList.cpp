#include <Platforms/DirectX12/DX12CommandList.h>

namespace wkr::render
{
  DX12CommandList::DX12CommandList(
      mem::Ref<Device> device,
      CommandList::Type listType,
      mem::Ref<CommandAllocator> commandAllocator,
      mem::Ref<PipelineState> pipelineState)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(listType),
        static_cast<ID3D12CommandAllocator*>(commandAllocator->GetNativeHandle()),
        static_cast<ID3D12PipelineState*>(pipelineState->GetNativeHandle()),
        IID_PPV_ARGS(&commandList));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command List");
  }

  DX12CommandList::~DX12CommandList()
  {
    commandList->Release();
  }
}
