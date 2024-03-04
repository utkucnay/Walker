#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::view
{
  class ResourceView
  {
  public:
    virtual ~ResourceView() {}

  public:
    virtual void*       GetNativeHandle() = 0;
    virtual std::string GetTypeName()     = 0;

  protected:
    mem::WeakRef<rsc::Resource> m_resource;
  };
}
