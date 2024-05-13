#pragma once

#include <Render/Render.h>

namespace wkr::render
{
  class AbstractFactory
  {
  public:
    //Core
    virtual mem::Scope<IFactory<IDevice, DeviceBuilder&>>
      GetDeviceFactory()        = 0;
    virtual mem::Scope<IFactory<IFence, FenceBuilder&>>
      GetFenceFactory()         = 0;
    virtual mem::Scope<IFactory<USwapChain, SwapChainBuilder&>>
      GetSwapChainFactory()     = 0;
    //virtual mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory() = 0;
    //virtual mem::Scope<Factory<RootSignature>>  GetRootSignatureFactory() = 0;

    //Command
    virtual mem::Scope<IFactory<ICommandQueue, CommandQueueBuilder&>>
      GetCommandQueueFactory()    = 0;
    virtual mem::Scope<IFactory<ICommandList, CommandListBuilder&>>
      GetCommandListFactory()     = 0;
    virtual mem::Scope<IFactory<ICommandAllocator, CommandAllocatorBuilder&>>
      GetCommandAllocaterFactory()= 0;

    //Descriptor
    virtual mem::Scope<IFactory<IDescriptorHeap, DescriptorHeapBuilder&>>
      GetDescriptorHeapFactory() = 0;

    //Resource
    virtual mem::Scope<IFactory<rsc::IHeap, rsc::HeapBuilder&>>
      GetHeapFactory()    = 0;
    virtual mem::Scope<IFactory<rsc::IBuffers, rsc::ResourceBuilder<rsc::IBuffers>&>>
      GetBuffersFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture1D>> GetTexture1DFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture2D>> GetTexture2DFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture3D>> GetTexture3DFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory() = 0;
    //virtual mem::Scope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory() = 0;

    //Barriers
    virtual mem::Scope<IFactory<rsc::bar::ITransitionBarrier, rsc::bar::TransitionBarrierBuilder&>>
      GetResourceBarrierTransition() = 0;
  };
}
