#pragma once

#include <Render/Resource/Buffer.h>
#include <Core/Window.h>
#include <Render/Core/Device.h>

namespace wkr::render {
  struct FRendererDesc
  {
    AWindowHandle window;
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

    ASwapChainHandle m_swapChain;

    mem::TScope<UBuffer> vertexBuffer;

  public:
    [[nodiscard]] static IDevice& GetDefaultDevice() {
      return s_defaultDevice.Get();
    }

  private:
    static inline IDeviceHandle s_defaultDevice;
  };
}
