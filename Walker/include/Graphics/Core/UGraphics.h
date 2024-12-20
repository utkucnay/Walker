#pragma once

#include "Graphics/RHI/Command/ICommandAllocator.h"
#include "Graphics/RHI/Command/ICommandList.h"
#include "Graphics/RHI/Core/ASwapChain.h"
#include "Graphics/RHI/Core/IDevice.h"
#include "Graphics/RHI/Core/IFence.h"
#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Shader/UVertexShader.h"
#include "OS/Window/AWindow.h"

namespace wkr::graphics {

struct FCommand {
  std::vector<rhi::ICommandAllocatorHandle> CommandAllocator;
  rhi::ICommandListHandle CommandList;
  rhi::ICommandQueueHandle CommandQueue;
};

struct WALKER_API FGraphicsDesc {
  os::AWindowHandle Window = {};
};

class WALKER_API UGraphics {
 public:
  explicit UGraphics(FGraphicsDesc& rendererDesc);
  ~UGraphics();

 public:
  void Render();
  void CreateResource();
  void LoadResources();
  void SwapBuffers();
  void Fence();

 private:
  rhi::IDeviceHandle m_Device;
  rhi::ASwapChainHandle m_SwapChain;
  rhi::AFenceHandle m_FenceHandle;
  FCommand m_DirectCommand;

  UBuffer m_VertexBuffer;
  UVertexShader m_VertexShader;

 public:
  [[nodiscard]] static rhi::IDevice& GetDefaultDevice() {
    return s_defaultDevice.Get();
  }

 private:
  static inline rhi::IDeviceHandle s_defaultDevice;
};

}  // namespace wkr::graphics
