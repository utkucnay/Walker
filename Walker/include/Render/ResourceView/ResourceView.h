#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::view
{
  class UResourceView
  {
  public:
    virtual ~UResourceView() {}

  public:
    b32 IsResourceExpired()
    {
      return m_resource.Expired();
    }

    template<typename T>
    mem::WeakRef<T> GetResource()
    {
      WKR_CORE_ERROR_COND(
          T::GetStaticTypeName() != m_resource.Lock()->GetTypeName(),
          "Resource Didn't Match "
            << T::GetStaticTypeName()
            << " "
            << m_resource.Lock()->GetTypeName());

      return static_cast<mem::WeakRef<T>>(m_resource);
    }

  public:
    virtual NativeHandle  GetNativeHandle() = 0;
    virtual std::string   GetTypeName()     = 0;

  protected:
    mem::WeakRef<rsc::IResource> m_resource;
  };
}
