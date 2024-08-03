#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render
{
  class UResourceView
  {
  public:
    virtual ~UResourceView() = default;

  public:
    b32 IsResourceExpired()
    {
      return m_resource.Expired();
    }

    template<typename T>
    mem::TWeakRef<T> GetResource()
    {
      WKR_CORE_ERROR_COND(
          T::GetStaticTypeName() != m_resource.Lock()->GetTypeName(),
          "Resource Didn't Match "
            << T::GetStaticTypeName()
            << " "
            << m_resource.Lock()->GetTypeName());

      return static_cast<mem::TWeakRef<T>>(m_resource);
    }

  public:
    virtual NativeObject  GetNativeObject() = 0;
    virtual std::string   GetTypeName()     = 0;

  public:
    mem::TWeakRef<IResource> m_resource;
  };

  using UResourceViewHandle = mem::TRef<UResourceView>;
}
