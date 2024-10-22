#pragma once

namespace wkr::render
{
  class IResourceView
  {
  public:
    virtual ~IResourceView() = default;

  public:
    virtual NativeObject  GetNativeObject() = 0;
    virtual std::string   GetTypeName()     = 0;
  };

  using IResourceViewHandle = mem::TRef<IResourceView>;
}
