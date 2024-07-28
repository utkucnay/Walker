#pragma once

#include <Render/Render.h>

namespace wkr::render
{
  class AbstractFactory
  {
  public:
    //Core
    virtual mem::TScope<IFactory<IDevice, FDeviceDesc&>>
      GetDeviceFactory()        = 0;
    virtual mem::TScope<IFactory<IFence, FFenceDesc&>>
      GetFenceFactory()         = 0;
    virtual mem::TScope<IFactory<USwapChain, SwapChainBuilder&>>
      GetSwapChainFactory()     = 0;
    virtual mem::TScope<IFactory<IRootSignature, FRootSignatureDesc&>>
      GetRootSignatureFactory() = 0;
    //virtual mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory() = 0;

    //Command
    virtual mem::TScope<IFactory<ICommandQueue, FCommandQueueDesc&>>
      GetCommandQueueFactory()    = 0;
    virtual mem::TScope<IFactory<ICommandList, FCommandListDesc&>>
      GetCommandListFactory()     = 0;
    virtual mem::TScope<IFactory<ICommandAllocator, FCommandAllocatorDesc&>>
      GetCommandAllocatorFactory()= 0;

    //Descriptor
    virtual mem::TScope<IFactory<IDescriptorHeap, DescriptorHeapBuilder&>>
      GetDescriptorHeapFactory() = 0;

    //Resource
    virtual mem::TScope<IFactory<rsc::IHeap, rsc::HeapBuilder&>>
      GetHeapFactory()    = 0;
    virtual mem::TScope<IFactory<rsc::IBuffers, rsc::ResourceBuilder<rsc::IBuffers>&>>
      GetBuffersFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture1D>> GetTexture1DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture2D>> GetTexture2DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture3D>> GetTexture3DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory() = 0;

    //Barriers
    virtual mem::TScope<IFactory<rsc::bar::ITransitionBarrier, rsc::bar::TransitionBarrierBuilder&>>
      GetTransitionBarrierFactory() = 0;
  };
}
