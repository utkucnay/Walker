#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Core/AbstractFactory.h>

namespace wkr::render::dx12
{
  //Core
  REGISTER_FACTORY(IDevice, UDevice, FDeviceDesc&);
  REGISTER_FACTORY(IFence, UFence, FFenceDesc&);
  REGISTER_FACTORY(wkr::render::USwapChain, USwapChain, FSwapChainDesc&);
  REGISTER_FACTORY(IPipelineState, UPipelineState, FPipelineStateDesc&);
  REGISTER_FACTORY(IRootSignature, URootSignature, FRootSignatureDesc&);

  //Command
  REGISTER_FACTORY(ICommandQueue, UCommandQueue, FCommandQueueDesc&);
  REGISTER_FACTORY(ICommandList, UCommandList, FCommandListDesc&);
  REGISTER_FACTORY(ICommandAllocator, UCommandAllocator, FCommandAllocatorDesc&);

  //Descriptor
  REGISTER_FACTORY(IDescriptorHeap, UDescriptorHeap, FDescriptorHeapDesc&);

  //Resource
  REGISTER_FACTORY(IHeap    , UHeap   , FHeapDesc&);
  REGISTER_FACTORY(IBuffers , UBuffers, FBuffersDesc&);
  //REGISTER_FACTORY(rsc::Texture1D,      rsc::DX12Texture1D);
  //REGISTER_FACTORY(rsc::Texture1DArray, rsc::DX12Texture1DArray);
  //REGISTER_FACTORY(Texture2D,      DX12Texture2D);
  //REGISTER_FACTORY(rsc::Texture2DArray, rsc::DX12Texture2DArray);
  //REGISTER_FACTORY(rsc::Texture3D,      rsc::DX12Texture3D);
  REGISTER_FACTORY(ITransitionBarrier, UTransitionBarrier, FTransitionBarrierDesc&);

  class UAbstractFactory : public IAbstractFactory
  {
  public:
    UAbstractFactory() { UDX12Factory::Init(); }

    //Core
    mem::Scope<IFactory<IDevice, FDeviceDesc&>>
      GetDeviceFactory() { return mem::Scope<UDeviceFactory>::Create(); }
    mem::Scope<IFactory<IFence, FFenceDesc&>>
      GetFenceFactory() { return mem::Scope<UFenceFactory>::Create(); }
    mem::Scope<IFactory<wkr::render::USwapChain, FSwapChainDesc&>>
      GetSwapChainFactory() { return mem::Scope<USwapChainFactory>::Create(); }
    //mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory();
    mem::Scope<IFactory<IRootSignature, FRootSignatureDesc&>>
      GetRootSignatureFactory() { return mem::Scope<URootSignatureFactory>::Create(); };

    //Command
    mem::Scope<IFactory<ICommandQueue, FCommandQueueDesc&>>
      GetCommandQueueFactory() { return mem::Scope<UCommandQueueFactory>::Create(); }
    mem::Scope<IFactory<ICommandList, FCommandListDesc&>>
      GetCommandListFactory() { return mem::Scope<UCommandListFactory>::Create(); }
    mem::Scope<IFactory<ICommandAllocator, FCommandAllocatorDesc&>>
      GetCommandAllocatorFactory() { return mem::Scope<UCommandAllocatorFactory>::Create(); }

    //Descriptor
    mem::Scope<IFactory<IDescriptorHeap, FDescriptorHeapDesc&>>
      GetDescriptorHeapFactory() { return mem::Scope<UDescriptorHeapFactory>::Create(); }

    //Resource
    virtual mem::Scope<IFactory<IHeap, FHeapDesc&>> GetHeapFactory()
    { return mem::Scope<UHeapFactory>::Create(); }
    mem::Scope<IFactory<IBuffers, FBuffersDesc&>> GetBuffersFactory()
    { return mem::Scope<rsc::UBuffersFactory>::Create();}
    //mem::Scope<Factory<rsc::Texture1D>> GetTexture1DFactory();
    //mem::Scope<Factory<rsc::Texture2D>> GetTexture2DFactory();
    //mem::Scope<Factory<rsc::Texture3D>> GetTexture3DFactory();

    //mem::Scope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory();
    //mem::Scope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory();

    //Resource Barrier
    virtual mem::Scope<IFactory<ITransitionBarrier, FTransitionBarrierDesc&>>
      GetTransitionBarrierFactory()
      { return mem::Scope<rsc::bar::UTransitionBarrierFactory>::Create();}
  };
}
