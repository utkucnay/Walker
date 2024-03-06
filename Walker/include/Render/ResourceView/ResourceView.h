#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::view
{
  class ResourceView
  {
  public:
    virtual ~ResourceView() {}

  public:
    template<typename T>
    T* GetResource()
    {
      if(m_resource.Expired()) return NULL;

      WKR_CORE_ERROR_COND(T::GetStaticTypeName() == m_resource.Lock()->GetTypeName()
          , "Resource Didn't Match");

      return static_cast<T*>(m_resource.Lock().Get());
    }

  public:
    virtual void*       GetNativeHandle() = 0;
    virtual std::string GetTypeName()     = 0;

  protected:
    mem::WeakRef<rsc::Resource> m_resource;
  };
}
