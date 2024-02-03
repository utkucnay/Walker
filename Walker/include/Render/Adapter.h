#pragma once

namespace wkr::render
{
  struct AdapterDesc
  {
    char description[128];
    uint32_t vendorId;
    uint32_t deviceID;
    uint32_t subSysID;
    uint32_t revision;
    std::size_t dedicatedVideoMemory;
    std::size_t dedicatedSystemMemory;
    std::size_t sharedSystemMemory;
    uint32_t adapterLuid;
    uint32_t flags;
  };


  class Adapter
  {
  public:
    static std::vector<Ref<Adapter>> GetAllAdapters();
    virtual void* GetNativeHandle() = 0;
  };

}
