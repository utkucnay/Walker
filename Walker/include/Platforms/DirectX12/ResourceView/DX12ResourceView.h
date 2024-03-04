#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceView/ResourceView.h>

namespace wkr::render::view
{
  class DX12ResourceView : public ResourceView
  {
  public:
    void* GetNativeHandle() { return &m_resourveViewHandle; }

  };
}
