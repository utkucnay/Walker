#pragma once

#include "Graphics/RHI/Command/ICommandAllocator.h"
#include "Graphics/RHI/Command/ICommandList.h"
#include "Graphics/RHI/Core/ASwapChain.h"
#include "Graphics/RHI/Core/IDevice.h"
#include "Graphics/RHI/Shader/IShader.h"
#include "Graphics/Resource/UBuffer.h"
#include "OS/Window/AWindow.h"

namespace wkr::graphics {

struct WALKER_API FGraphicsDesc {
  os::AWindowHandle window = {};
};

class WALKER_API UGraphics {
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

  rhi::ASwapChainHandle m_swapChain;

  mem::TScope<rsc::UBuffer> vertexBuffer;
  mem::TScope<rhi::IShader> vertexShader;

 public:
  [[nodiscard]] static rhi::IDevice& GetDefaultDevice() {
    return s_defaultDevice.Get();
  }

 private:
  static inline rhi::IDeviceHandle s_defaultDevice;
};

}  // namespace wkr::graphics
