#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render
{
  struct FBuffersDesc
  {

  };

  class IBuffers : public IResource
  {
  public:
    virtual ~IBuffers() override = default;

  public:
    virtual u64 GetSize() = 0;

  public:
    std::string GetTypeName() override final { return "Buffers"; }
    static std::string GetStaticTypeName() { return "Buffers"; }
  };

  using IBuffersHandle = mem::TRef<IBuffers>;
}
