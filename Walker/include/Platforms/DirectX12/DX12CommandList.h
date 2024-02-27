#pragma once

#include <Render/Command.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandList : public CommandList
  {
  public:
    DX12CommandList(
        Device*           device,
        CommandList::Type listType,
        CommandAllocator* commandAllocator,
        PipelineState*    PipelineState);

    ~DX12CommandList() override;

  public:
    void* GetNativeHandle() override { return m_commandList; }

  private:
    ID3D12GraphicsCommandList* m_commandList;
  };
}
