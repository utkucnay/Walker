#pragma once

namespace wkr::render::rsc
{
  class Resource
  {
  public:
    virtual ~Resource() {}

  public:
    virtual void* GetNativeHandle() = 0;

    virtual std::string GetTypeName() = 0;
  };
}
