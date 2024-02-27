#include <Platforms/DirectX12/DX12CommandList.h>

namespace wkr::render
{

  DX12CommandList::DX12CommandList(
      mem::Visitor<Device>            device,
      CommandList::Type               listType,
      mem::Visitor<CommandAllocator>  commandAllocator)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();
    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(listType),
        static_cast<ID3D12CommandAllocator*>(commandAllocator->GetNativeHandle()),
        NULL,
        IID_PPV_ARGS(&m_commandList));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command List");
  }

  DX12CommandList::DX12CommandList(
      mem::Visitor<Device>            device,
      CommandList::Type               listType,
      mem::Visitor<CommandAllocator>  commandAllocator,
      mem::Visitor<PipelineState>     pipelineState)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();
    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(listType),
        static_cast<ID3D12CommandAllocator*>(commandAllocator->GetNativeHandle()),
        static_cast<ID3D12PipelineState*>(pipelineState->GetNativeHandle()),
        IID_PPV_ARGS(&m_commandList));
    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command List");
  }

  DX12CommandList::~DX12CommandList()
  {
    m_commandList->Release();
  }
}
