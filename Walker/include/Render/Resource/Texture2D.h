#pragma once

namespace wkr::render::rsc
{
  class Texture2D
  {
  public:
    virtual ~Texture2D() {}

  public:
    virtual void*     GetNativeHandle() = 0;
    virtual uint64_t  GetWidth()        = 0;
    virtual uint64_t  GetHeight()       = 0;
  };
}
