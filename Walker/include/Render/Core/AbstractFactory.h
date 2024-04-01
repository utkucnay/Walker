#pragma once

#include <Render/Render.h>

namespace wkr::render
{
  class AbstractFactory
  {
  public:
    //Core
    virtual mem::Scope<Factory<Device, DeviceBuilder*>>
      GetDeviceFactory()        = 0;
    virtual mem::Scope<Factory<Fence, FenceBuilder*>>
      GetFenceFactory()         = 0;
    virtual mem::Scope<Factory<SwapChain, SwapChainBuilder*>>
      GetSwapChainFactory()     = 0;
    //virtual mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory() = 0;
    //virtual mem::Scope<Factory<RootSignature>>  GetRootSignatureFactory() = 0;

    //Command
    virtual mem::Scope<Factory<CommandQueue, CommandQueueBuilder*>>
      GetCommandQueueFactory()    = 0;
    virtual mem::Scope<Factory<CommandList, CommandListBuilder*>>
      GetCommandListFactory()     = 0;
    virtual mem::Scope<Factory<CommandAllocator, CommandAllocatorBuilder*>>
      GetCommandAllocaterFactory()= 0;

    //Descriptor
    virtual mem::Scope<Factory<DescriptorHeap, DescriptorHeapBuilder*>>
      GetDescriptorHeapFactory() = 0;

    //Resource
    virtual mem::Scope<Factory<rsc::Heap, rsc::HeapBuilder*>>
      GetHeapFactory()    = 0;
    virtual mem::Scope<Factory<rsc::Buffers, rsc::ResourceBuilder<rsc::Buffers>*>>
      GetBuffersFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture1D>> GetTexture1DFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture2D>> GetTexture2DFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture3D>> GetTexture3DFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory() = 0;

    //Barriers
    virtual mem::Scope<Factory<rsc::bar::TransitionBarrier, rsc::bar::TransitionBarrierBuilder*>>
      GetResourceBarrierTransition() = 0;
  };
}
