#pragma once

#include "Core/AWindow.h"
#include "Graphics/Core/IDevice.h"
#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Shader/IShader.h"

namespace wkr::graphics {

struct FGraphicsDesc {
  AWindowHandle window = {};
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
  rhi::IDeviceHandle m_device;

  std::vector<rhi::ICommandAllocatorHandle> m_commandDirectAllocator;
  rhi::ICommandListHandle m_commandDirectList;
  rhi::ICommandQueueHandle m_commandDirectQueue;

  ASwapChainHandle m_swapChain;

  mem::TScope<rhi::UBuffer> vertexBuffer;
  mem::TScope<rhi::IShader> vertexShader;

 public:
  [[nodiscard]] static rhi::IDevice& GetDefaultDevice() {
    return s_defaultDevice.Get();
  }

 private:
  static inline rhi::IDeviceHandle s_defaultDevice;
};

}  // namespace wkr::render
