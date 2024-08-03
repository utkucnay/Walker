#pragma once

#include <Render/Render.h>

namespace wkr::render
{
  class IAbstractFactory
  {
  public:
    //Core
    virtual mem::TScope<IFactory<IDevice, FDeviceDesc&>>
      GetDeviceFactory()        = 0;
    virtual mem::TScope<IFactory<IFence, FFenceDesc&>>
      GetFenceFactory()         = 0;
    virtual mem::TScope<IFactory<USwapChain, FSwapChainDesc&>>
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
    virtual mem::TScope<IFactory<IDescriptorHeap, FDescriptorHeapDesc&>>
      GetDescriptorHeapFactory() = 0;

    //Resource
    virtual mem::TScope<IFactory<IHeap, FHeapDesc&>>
      GetHeapFactory()    = 0;
    virtual mem::TScope<IFactory<IBuffers, FBuffersDesc&>>
      GetBuffersFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture1D>> GetTexture1DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture2D>> GetTexture2DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture3D>> GetTexture3DFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory() = 0;
    //virtual mem::TScope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory() = 0;

    //Barriers
    virtual mem::TScope<IFactory<ITransitionBarrier, FTransitionBarrierDesc&>>
      GetTransitionBarrierFactory() = 0;
  };
}
