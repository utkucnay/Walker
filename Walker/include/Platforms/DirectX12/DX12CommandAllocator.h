#pragma once

#include <Render/Command.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandAllocator : public CommandAllocator
  {
  public:
    DX12CommandAllocator(
        mem::Visitor<Device> device,
        CommandList::Type listType);
    ~DX12CommandAllocator() override;

  public:
    void* GetNativeHandle() override { return commandAllocator; }

  private:
    ID3D12CommandAllocator* commandAllocator;
  };
}
