#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceView/RenderTargetView.h>

namespace wkr::render::dx12
{
  class URenderTargetView : public wkr::render::URenderTargetView
  {
  public:
    URenderTargetView(
        CD3_CPU_DESCRIPTOR_HANDLE handle,
        IResourceHandle res)
      : m_resourveViewHandle(handle) { m_resource = res; }

    ~URenderTargetView() override;

  public:
    NativeObject GetNativeObject() override final { return &m_resourveViewHandle; }

  protected:
    CD3DX12_CPU_DESCRIPTOR_HANDLE m_resourveViewHandle;
  };
}
