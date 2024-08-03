#pragma once

#include <Render/Command/CommandTypes.h>

namespace wkr::render
{
  struct FCommandAllocatorDesc
  {
    ECommandType commandType;
  };

  class ICommandAllocator
  {
  public:
    virtual ~ICommandAllocator() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;
    virtual ECommandType GetCommandType() = 0;
    virtual void Reset() = 0;
  };

  using ICommandAllocatorHandle = mem::TRef<ICommandAllocator>;
}
