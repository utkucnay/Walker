#pragma once

#include "Graphics/Command/ICommandAllocator.h"

namespace wkr::render::dx12
{
  class UCommandAllocator : public ICommandAllocator
  {
  public:
    UCommandAllocator(FCommandAllocatorDesc& desc);
    ~UCommandAllocator() override;

  public:
    inline NativeObject GetNativeObject() override { return m_commandAllocator; }
    ECommandType GetCommandType() override final;
    void Reset() override final;

  private:
    ID3D12CommandAllocator* m_commandAllocator;
    ECommandType      m_listType;
  };
}
