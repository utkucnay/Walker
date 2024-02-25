#pragma once

#include <Render/Command.h>

namespace wkr::render
{
  class DX12CommandList : public CommandList
  {
  public:
    DX12CommandList(
        mem::Ref<Device> device,
        CommandList::Type listType,
        mem::Ref<CommandAllocator> commandAllocator,
        mem::Ref<PipelineState> PipelineState);

    ~DX12CommandList() override;

  public:
    void* GetNativeHandle() override { return commandList; }

  private:
    ID3D12GraphicsCommandList* commandList;
  };
}
