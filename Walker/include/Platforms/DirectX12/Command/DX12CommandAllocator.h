#pragma once

#include <Render/Command/CommandAllocator.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12CommandAllocator : public CommandAllocator
  {
  public:
    DX12CommandAllocator(
        CommandAllocatorBuilder* cab);
    ~DX12CommandAllocator() override;

  public:
    void* GetNativeHandle() override { return m_commandAllocator; }
    void Reset() override final;

  private:
    ID3D12CommandAllocator* m_commandAllocator;
  };
}
