#pragma once

#include <Render/Core/SwapChain.h>
#include <Render/Core/Device.h>
#include <Render/Descriptor/DescriptorHeap.h>

namespace wkr::render::view
{
  class RenderTargetViewBuilder;
  class SwapChain;

  class RenderTargetView
  {
  public:
    virtual ~RenderTargetView() {}

  public:
    virtual void* GetNativeHandle() = 0;
  };

  class RenderTargetViewBuilder : Builder<
                                  RenderTargetView,
                                  mem::Visitor<Device>>
  {
  public:
    void SetDescriptorHeap(DescriptorHeap* dhb);
    void SetSwapChain(SwapChain* swapChain);
    void SetIndex(int index);
    int GetIndex() const { return m_currentIndex; }

  public:
    RenderTargetView*             BuildRaw(
        mem::Visitor<Device> device) override final;
    mem::Ref<RenderTargetView>    BuildRef(
        mem::Visitor<Device> device) override final;
    mem::Scope<RenderTargetView>  BuildScope(
        mem::Visitor<Device> device) override final;

  private:
    DescriptorHeap* m_dHeap;
    SwapChain*      m_swapChain;
    int             m_currentIndex;

    friend class RenderTargetView;
  };

  class RenderTargetViewFactory : Factory<
                                  RenderTargetView,
                                  mem::Visitor<Device>,
                                  mem::Scope<DescriptorHeap>>
  {
  public:
    RenderTargetView* CreateFactoryRaw(
        mem::Visitor<Device> device,
        mem::Scope<DescriptorHeap> dhb) override final;
    mem::Ref<RenderTargetView> CreateFactoryRef(
        mem::Visitor<Device> device,
        mem::Scope<DescriptorHeap> dhb) override final;
    mem::Scope<RenderTargetView> CreateFactoryScope(
        mem::Visitor<Device> device,
        mem::Scope<DescriptorHeap> dhb) override final;
  };
}
