#pragma once

#include "Graphics/RHI/Core/IAdapter.h"

namespace wkr::graphics::rhi::dx12 {

class UAdapter : public IAdapter {
 public:
  UAdapter(IDXGIAdapter1* adapter) : m_adapter(adapter) {}

  ~UAdapter() override;
  UAdapter() = delete;

 public:
  NativeObject GetNativeObject() override { return m_adapter; }

  virtual FAdapterDesc GetDesc() override final;

 private:
  IDXGIAdapter1* m_adapter;
};

}  // namespace wkr::graphics::rhi::dx12
