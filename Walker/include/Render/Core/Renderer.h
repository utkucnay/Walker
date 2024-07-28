#pragma once

#include <Core/Window.h>
#include <Render/Core/SwapChain.h>
#include <Render/Core/RootSignature.h>
#include <Render/Resource/Buffers.h>
#include <Render/Command/CommandList.h>
#include <Render/Command/CommandQueue.h>
#include <Render/Command/CommandAllocator.h>

namespace wkr::render {
  class URenderer {
  public:
    URenderer(mem::TWeakRef<UWindow> window);
    ~URenderer();

  public:
    void Render();
    void CreateSwapChain(mem::TWeakRef<UWindow> window);
    void CreateResource();
    void LoadResources();

  private:
    DeviceHandle m_device;

    std::vector<ICommandAllocatorHandle> m_commandDirectAllocator;
    ICommandListHandle                   m_commandDirectList;
    ICommandQueueHandle                  m_commandDirectQueue;

    USwapChainHandle m_swapChain;

    rsc::BuffersHandle m_vertexBuffer;
    rsc::BuffersHandle m_vertexUploadBuffer;

    RootSignatureHandle m_rootSignature;

  public:
    [[nodiscard]] static IDevice& GetDefaultDevice() {
      return s_defaultDevice.Get();
    }

  private:
    static inline DeviceHandle s_defaultDevice;
  };
}
