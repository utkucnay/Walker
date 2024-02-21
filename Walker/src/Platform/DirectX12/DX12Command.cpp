#include "Render/PipelineState.h"
#include "d3d12.h"
#include <Platforms/DirectX12/DX12Command.h>

namespace wkr::render
{
  DX12CommandAllocator::DX12CommandAllocator(
      Ref<Device> device,
      CommandListType listType)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandAllocator(
        static_cast<D3D12_COMMAND_LIST_TYPE>(listType),
        IID_PPV_ARGS(&commandAllocator));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command Allocator");
  }

  DX12CommandAllocator::~DX12CommandAllocator()
  {
    commandAllocator->Release();
  }

  DX12CommandList::DX12CommandList(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(commandAllocator->type),
        static_cast<ID3D12CommandAllocator*>(commandAllocator->GetNativeHandle()),
        NULL,
        IID_PPV_ARGS(&commandList));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command List");
  }

  DX12CommandList::DX12CommandList(
      Ref<Device> device,
      Ref<CommandAllocator> commandAllocator,
      Ref<PipelineState> pipelineState)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(commandAllocator->type),
        static_cast<ID3D12CommandAllocator*>(commandAllocator->GetNativeHandle()),
        static_cast<ID3D12PipelineState*>(pipelineState->GetNativeHandle()),
        IID_PPV_ARGS(&commandList));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Command List");
  }

  DX12CommandList::~DX12CommandList()
  {
    commandList->Release();
  }

  DX12CommandQueue::DX12CommandQueue(
      Ref<Device> device,
      CommandQueueDesc& desc)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();
    D3D12_COMMAND_QUEUE_DESC nDesc = {};

    nDesc.Type =      static_cast<D3D12_COMMAND_LIST_TYPE>  (desc.listType);
    nDesc.Priority =  static_cast<INT>                      (desc.priority);
    nDesc.Flags =     static_cast<D3D12_COMMAND_QUEUE_FLAGS>(desc.flags);

    HRESULT hr = nDevice->CreateCommandQueue(&nDesc, IID_PPV_ARGS(&commandQueue));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Command Queue");
  }

  DX12CommandQueue::~DX12CommandQueue()
  {
    commandQueue->Release();
  }
}
