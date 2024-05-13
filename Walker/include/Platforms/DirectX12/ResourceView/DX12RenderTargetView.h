#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceView/RenderTargetView.h>

namespace wkr::render::view
{
  class UDX12RenderTargetView : public URenderTargetView
  {
  public:
    UDX12RenderTargetView(
        CD3DX12_CPU_DESCRIPTOR_HANDLE handle,
        mem::WeakRef<rsc::IResource> res)
      : m_resourveViewHandle(handle) { m_resource = res; }

    ~UDX12RenderTargetView() override;

  public:
    NativeHandle GetNativeHandle() override final { return &m_resourveViewHandle; }

  protected:
    CD3DX12_CPU_DESCRIPTOR_HANDLE m_resourveViewHandle;
  };
}
