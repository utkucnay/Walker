#pragma once

#include <Render/Core/RendererStructs.h>

namespace wkr::render
{
  class Adapter
  {
  public:
    virtual ~Adapter() {}

  public:
    virtual void* GetNativeHandle() = 0;

    virtual mem::Scope<char> GetName() = 0;

    virtual uint32_t GetVendorID() = 0;
    virtual uint32_t GetDeviceID() = 0;
    virtual uint32_t GetSubSysID() = 0;
    virtual uint32_t GetRevision() = 0;

    virtual Luid GetAdapterLuid() = 0;

    virtual uint64_t GetDedicatedVideoMemory()  = 0;
    virtual uint64_t GetDedicatedSystemMemory() = 0;
    virtual uint64_t GetSharedSystemMemory()    = 0;

  public:
    static std::vector<mem::Ref<Adapter>> GetAllAdapters();
  };
}
