#pragma once

#include <Render/Descriptor/DescriptorHeap.h>
#include <Render/Core/CoreTypes.h>
#include <Render/Resource/ResourceTypes.h>
#include <Core/Window.h>
#include <Render/Command/CommandQueue.h>
#include <Render/Core/Fence.h>

namespace wkr
{
  class UWindow;
  using UWindowHandle = mem::TRef<UWindow>;
}

namespace wkr::render
{
  struct FSwapChainDesc
  {
    u32                           m_bufferCount;
    FSample                       m_sampleDesc;
    ESwapChainFlag                m_flag;
    ESwapChainEffect              m_swapEffect;
    UWindowHandle                 m_window;
    FModeDesc                     m_bufferDesc;
    EResourceUsage                m_bufferUsage;
    mem::TWeakRef<ICommandQueue>  m_commandQueue;
  };

  class USwapChain
  {
  public:
    virtual ~USwapChain() = default;

  public:
    virtual void WindowSizeEvent(u32 width, u32 height) = 0;
    virtual void FullscreenEvent(b64 isTrue) = 0;

    virtual void SwapBuffers() = 0;

    virtual NativeObject GetNativeObject() = 0;

    virtual u32                 GetBufferCount()  = 0;
    virtual FSample             GetSampleDesc()   = 0;
    virtual FModeDesc           GetBufferDesc()   = 0;
    virtual ESwapChainFlag      GetFlag()         = 0;
    virtual ESwapChainEffect    GetSwapEffect()   = 0;
    virtual EResourceUsage      GetBufferUsage()  = 0;

    [[nodiscard]] virtual IFence& GetCurrentFence() { return m_fence.Get(); }

    virtual void Present(u8 syncInterval, u8 flags) = 0;

  public:
    virtual u32 GetFrameIndex() { return m_frameIndex; }
    [[nodiscard]] URenderTargetViewHandle GetCurrentRenderTarget()
    {
      return m_descripHeap->Get<URenderTargetView>(GetFrameIndex());
    }

  protected:
    WindowResizeEvent::FEvent        m_resizeEvent;
    WindowSetFullscreenEvent::FEvent m_fullscreenEvent;

    u32 m_frameIndex;

    mem::TScope<IFence> m_fence;
    IDescriptorHeapHandle m_descripHeap;
  };

  using USwapChainHandle = mem::TRef<USwapChain>;
}
