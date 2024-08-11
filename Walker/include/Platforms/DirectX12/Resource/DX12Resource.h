#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::dx12
{
  class UResource : public IResource
  {
    public:
      UResource(FResourceDesc& desc);
      UResource(ID3D12Resource* resource) : m_resource(resource) {};
      ~UResource() override;

    public:
      NativeObject GetNativeObject() override final { return m_resource; }

    private:
      ID3D12Resource* m_resource;
  };
}
