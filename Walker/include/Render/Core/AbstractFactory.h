#pragma once

#include <Render/Render.h>

namespace wkr::render
{
  class IAbstractFactory
  {
  public:
    //Core
    virtual mem::TScope<IFactory<IDevice, FDeviceDesc&>>
      GetIDeviceFactory()        = 0;
    virtual mem::TScope<IFactory<IFence, FFenceDesc&>>
      GetIFenceFactory()         = 0;
    virtual mem::TScope<IFactory<ASwapChain, FSwapChainDesc&>>
      GetASwapChainFactory()     = 0;
    virtual mem::TScope<IFactory<IRootSignature, FRootSignatureDesc&>>
      GetIRootSignatureFactory() = 0;
    //virtual mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory() = 0;

    //Command
    virtual mem::TScope<IFactory<ICommandQueue, FCommandQueueDesc&>>
      GetICommandQueueFactory()    = 0;
    virtual mem::TScope<IFactory<ICommandList, FCommandListDesc&>>
      GetICommandListFactory()     = 0;
    virtual mem::TScope<IFactory<ICommandAllocator, FCommandAllocatorDesc&>>
      GetICommandAllocatorFactory()= 0;

    //Descriptor
    virtual mem::TScope<IFactory<IDescriptorHeap, FDescriptorHeapDesc&>>
      GetIDescriptorHeapFactory() = 0;

    //Resource
    virtual mem::TScope<IFactory<IHeap, FHeapDesc&>>
      GetIHeapFactory()    = 0;
    virtual mem::TScope<IFactory<IBuffers, FBuffersDesc&>>
      GetIBuffersFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture1D>> GetTexture1DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture2D>> GetTexture2DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture3D>> GetTexture3DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory() = 0;

    //Barriers
    virtual mem::TScope<IFactory<ITransitionBarrier, FTransitionBarrierDesc&>>
      GetITransitionBarrierFactory() = 0;
  };
}
