#pragma once

#include "Core/AWindow.h"
#include "Graphics/Core/IDevice.h"
#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Shader/IShader.h"

namespace wkr::render {

struct FGraphicsDesc {
  AWindowHandle window;
};

class UGraphics {
 public:
  UGraphics(FGraphicsDesc& rendererDesc);
  ~UGraphics();

 public:
  void Render();
  void CreateResource();
  void LoadResources();

 private:
  IDeviceHandle m_device;

  std::vector<ICommandAllocatorHandle> m_commandDirectAllocator;
  ICommandListHandle m_commandDirectList;
  ICommandQueueHandle m_commandDirectQueue;

  ASwapChainHandle m_swapChain;

  mem::TScope<UBuffer> vertexBuffer;
  mem::TScope<IShader> vertexShader;

 public:
  [[nodiscard]] static IDevice& GetDefaultDevice() {
    return s_defaultDevice.Get();
  }

 private:
  static inline IDeviceHandle s_defaultDevice;
};

}  // namespace wkr::render
