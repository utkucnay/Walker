#pragma once

#include <Core/Window.h>
#include <Render/Core/SwapChain.h>
#include <Render/Resource/Buffers.h>

namespace wkr::render {
class URenderer {
public:
  URenderer(mem::WeakRef<UWindow> window);
  ~URenderer();

public:
  void Render();
  void CreateSwapChain(mem::WeakRef<UWindow> window);
  void CreateResource();
  void LoadResources();

private:
  mem::Ref<IDevice> m_device;

  std::vector<mem::Ref<ICommandAllocator>> m_commandDirectAllocator;
  mem::Ref<ICommandList> m_commandDirectList;
  mem::Ref<ICommandQueue> m_commandDirectQueue;

  std::vector<mem::Ref<ICommandAllocator>> m_commandCopyAllocator;
  mem::Ref<ICommandList> m_commandCopyList;
  mem::Ref<ICommandQueue> m_commandCopyQueue;

  mem::Ref<USwapChain> m_swapChain;

  mem::Ref<rsc::IBuffers> m_vertexBuffer;
  mem::Ref<rsc::IBuffers> m_vertexUploadBuffer;

  // std::queue<ResourceLoadCommand> m_resourceCommandLoad;
public:
  [[nodiscard]] static IDevice &GetDefaultDevice() {
    return s_defaultDevice.Get();
  }

private:
  static inline mem::Ref<IDevice> s_defaultDevice;
};
} // namespace wkr::render
