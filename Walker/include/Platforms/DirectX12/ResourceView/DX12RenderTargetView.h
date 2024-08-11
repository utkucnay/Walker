#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceView/RenderTargetView.h>

namespace wkr::render::dx12
{
  class URenderTargetView : public ARenderTargetView
  {
  public:
    URenderTargetView(
        CD3DX12_CPU_DESCRIPTOR_HANDLE handle,
        mem::TRef<UTexture2D> texture2d)
      : m_resourveViewHandle(handle) { m_texture2D = texture2d; }

    ~URenderTargetView() override;

  public:
    NativeObject GetNativeObject() override final { return &m_resourveViewHandle; }

  protected:
    CD3DX12_CPU_DESCRIPTOR_HANDLE m_resourveViewHandle;
  };
}
