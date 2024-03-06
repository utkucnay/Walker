#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceView/RenderTargetView.h>

namespace wkr::render::view
{
  class DX12RenderTargetView : public RenderTargetView
  {
  public:
    DX12RenderTargetView(
        CD3DX12_CPU_DESCRIPTOR_HANDLE handle,
        mem::WeakRef<rsc::Resource> res)
      : m_resourveViewHandle(handle) { m_resource = res; }

    ~DX12RenderTargetView() override;

  public:
    void* GetNativeHandle() override final { return &m_resourveViewHandle; }

  protected:
    CD3DX12_CPU_DESCRIPTOR_HANDLE m_resourveViewHandle;
  };
}
