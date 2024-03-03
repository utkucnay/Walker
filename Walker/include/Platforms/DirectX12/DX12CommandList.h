#pragma once

#include <Render/Command/CommandList.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandList : public CommandList
  {
  public:
    DX12CommandList(
        mem::Visitor<Device>              device,
        mem::Visitor<CommandListBuilder>  clb
        );
    ~DX12CommandList() override;

  public:
    void* GetNativeHandle() override { return m_commandList; }

  private:
    ID3D12GraphicsCommandList* m_commandList;
  };
}
