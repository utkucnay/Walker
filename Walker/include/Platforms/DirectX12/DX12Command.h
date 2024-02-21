#pragma once

#include "Render/Device.h"
#include <Platforms/DirectX12/DX12.h>

#include <Render/PipelineState.h>
#include <Render/Command.h>

namespace wkr::render
{
  class DX12CommandAllocator : public CommandAllocator
  {
  public:
    DX12CommandAllocator(Ref<Device> device, CommandListType listType);
    ~DX12CommandAllocator();

  public:
    void* GetNativeHandle() override { return commandAllocator; }

  private:
    ID3D12CommandAllocator* commandAllocator;
  };

  class DX12CommandList : public CommandList
  {
  public:
    DX12CommandList(
        Ref<Device> device,
        Ref<CommandAllocator> commandAllocator);

    DX12CommandList(
        Ref<Device> device,
        Ref<CommandAllocator> commandAllocator,
        Ref<PipelineState> PipelineState);

    ~DX12CommandList();

  public:
    void* GetNativeHandle() override { return commandList; }

  private:
    ID3D12GraphicsCommandList* commandList;
  };

  class DX12CommandQueue : public CommandQueue
  {
  public:
    DX12CommandQueue(Ref<Device> device, CommandQueueDesc& desc);
    ~DX12CommandQueue();

  public:
    void* GetNativeHandle() override { return commandQueue; }

  private:
    ID3D12CommandQueue* commandQueue;
  };
}
