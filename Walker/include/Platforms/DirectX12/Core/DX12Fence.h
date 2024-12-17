#pragma once

#include "Graphics/RHI/Core/IFence.h"

namespace wkr::graphics::rhi::dx12 {

class UFence : public AFence {
 public:
  UFence(FFenceDesc& desc);
  ~UFence() override;

 public:
  void FenceEvent(int frameIndex) override final;

  NativeObject GetNativeObject(int frameIndex) override final {
    return m_Fence[frameIndex];
  }

  FFenceDesc GetDesc() override final;

 private:
  HANDLE m_FenceEvent;
  std::vector<ID3D12Fence*> m_Fence;
  FFenceDesc m_Desc;
};

}  // namespace wkr::graphics::rhi::dx12
