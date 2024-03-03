#include <Platforms/DirectX12/DX12CommandList.h>

namespace wkr::render
{

  DX12CommandList::DX12CommandList(
      mem::Visitor<Device>              device,
      mem::Visitor<CommandListBuilder>  clb)
    : CommandList(clb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();
    auto [commandAllocator, pipelineState] = clb->GetPointers();

    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(m_type),
        static_cast<ID3D12CommandAllocator*>(
          commandAllocator->GetNativeHandle()),
        NULL == pipelineState ?
        NULL :
        static_cast<ID3D12PipelineState*>(pipelineState->GetNativeHandle()),
        IID_PPV_ARGS(&m_commandList));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command List");
    WKR_CORE_LOG("Created DX12 Command List");
  }

  DX12CommandList::~DX12CommandList()
  {
    m_commandList->Release();
  }
}
