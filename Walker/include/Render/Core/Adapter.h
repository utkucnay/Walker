#pragma once

#include <Render/Core/RendererStructs.h>

namespace wkr::render
{
  class IAdapter : public ICloneable<IAdapter>
  {
  public:
    virtual ~IAdapter() {}

  public:
    virtual void* GetNativeHandle() = 0;

    virtual mem::Scope<char> GetName() = 0;

    virtual u32 GetVendorID() = 0;
    virtual u32 GetDeviceID() = 0;
    virtual u32 GetSubSysID() = 0;
    virtual u32 GetRevision() = 0;

    virtual Luid GetAdapterLuid() = 0;

    virtual u64 GetDedicatedVideoMemory()  = 0;
    virtual u64 GetDedicatedSystemMemory() = 0;
    virtual u64 GetSharedSystemMemory()    = 0;

  public:
    static std::vector<mem::Ref<IAdapter>> GetAllAdapters();
  };
}
