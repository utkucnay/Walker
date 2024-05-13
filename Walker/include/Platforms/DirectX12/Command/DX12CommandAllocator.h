#pragma once

#include <Render/Command/CommandAllocator.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12CommandAllocator : public ICommandAllocator
  {
  public:
    UDX12CommandAllocator(CommandAllocatorBuilder& cab);
    ~UDX12CommandAllocator() override;

  public:
    NativeHandle GetNativeHandle() override { return m_commandAllocator; }
    ICommandList::Type GetCommandListType() override final;
    void Reset() override final;

  protected:
    void Clone(ICommandAllocator& commandAllocator) override final;

  private:
    ID3D12CommandAllocator* m_commandAllocator;
    ICommandList::Type      m_listType;
  };
}
