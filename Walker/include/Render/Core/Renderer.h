#pragma once

#include <Core/Window.h>
#include <Render/Core/Device.h>

namespace wkr::render {
  struct FRendererDesc
  {
    UWindowHandle window;
  };

  class URenderer {
  public:
    URenderer(FRendererDesc& rendererDesc);
    ~URenderer();

  public:
    void Render();
    void CreateResource();
    void LoadResources();

  private:
    IDeviceHandle m_device;

    std::vector<ICommandAllocatorHandle> m_commandDirectAllocator;
    ICommandListHandle                   m_commandDirectList;
    ICommandQueueHandle                  m_commandDirectQueue;

    USwapChainHandle m_swapChain;

  public:
    [[nodiscard]] static IDevice& GetDefaultDevice() {
      return s_defaultDevice.Get();
    }

  private:
    static inline IDeviceHandle s_defaultDevice;
  };

  using URendererHandle = mem::TRef<URenderer>;
}
