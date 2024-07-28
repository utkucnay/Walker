#pragma once

#include <Render/Core/RendererStructs.h>

namespace wkr::render
{
  class IAdapter
  {
  public:
    virtual ~IAdapter() {}

  public:
    virtual NativeObject GetNativeObject() = 0;

    virtual std::string GetName() = 0;

    virtual u32 GetVendorID() = 0;
    virtual u32 GetDeviceID() = 0;
    virtual u32 GetSubSysID() = 0;
    virtual u32 GetRevision() = 0;

    virtual FLuid GetAdapterLuid() = 0;

    virtual u64 GetDedicatedVideoMemory()  = 0;
    virtual u64 GetDedicatedSystemMemory() = 0;
    virtual u64 GetSharedSystemMemory()    = 0;

  public:
    static std::vector<mem::TRef<IAdapter>> GetAllAdapters();
  };

  using IAdapterHandle = mem::TRef<IAdapter>;
}
