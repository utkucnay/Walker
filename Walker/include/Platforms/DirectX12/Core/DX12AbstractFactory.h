#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Core/AbstractFactory.h>

namespace wkr::render::dx12
{
  //Core
  REGISTER_FACTORY(IDevice, UDevice, FDeviceDesc&);
  REGISTER_FACTORY(IFence, UFence, FFenceDesc&);
  REGISTER_FACTORY(ASwapChain, USwapChain, FSwapChainDesc&);
  //REGISTER_FACTORY(IPipelineState, UPipelineState, FPipelineStateDesc&);
  REGISTER_FACTORY(IRootSignature, URootSignature, FRootSignatureDesc&);

  //Command
  REGISTER_FACTORY(ICommandQueue, UCommandQueue, FCommandQueueDesc&);
  REGISTER_FACTORY(ICommandList, UCommandList, FCommandListDesc&);
  REGISTER_FACTORY(ICommandAllocator, UCommandAllocator, FCommandAllocatorDesc&);

  //Descriptor
  REGISTER_FACTORY(IDescriptorHeap, UDescriptorHeap, FDescriptorHeapDesc&);

  //Resource
  REGISTER_FACTORY(IHeap , UHeap, FHeapDesc&);
  REGISTER_FACTORY(IResource, UResource, FResourceDesc&);
  REGISTER_FACTORY(IShader, UShader, FShaderDesc&);

  REGISTER_FACTORY(ITransitionBarrier, UTransitionBarrier, FTransitionBarrierDesc&);

  BEGIN_ABSTRACT_FACTORY()
    CTOR_ABSTRACT_FACTORY(UDX12Factory::Init();)

    //Core
    SUBS_ABSTRACT_FACTORY(IDevice, UDevice, FDeviceDesc&);
    SUBS_ABSTRACT_FACTORY(IFence, UFence, FFenceDesc&);
    SUBS_ABSTRACT_FACTORY(ASwapChain, USwapChain, FSwapChainDesc&);
    SUBS_ABSTRACT_FACTORY(IRootSignature, URootSignature, FRootSignatureDesc&);

    //Command
    SUBS_ABSTRACT_FACTORY(ICommandQueue, UCommandQueue, FCommandQueueDesc&);
    SUBS_ABSTRACT_FACTORY(ICommandList, UCommandList, FCommandListDesc&);
    SUBS_ABSTRACT_FACTORY(ICommandAllocator, UCommandAllocator, FCommandAllocatorDesc&);

    //Descriptor
    SUBS_ABSTRACT_FACTORY(IDescriptorHeap, UDescriptorHeap, FDescriptorHeapDesc&);

    //Resource
    SUBS_ABSTRACT_FACTORY(IHeap , UHeap, FHeapDesc&);
    SUBS_ABSTRACT_FACTORY(IResource, UResource, FResourceDesc&);
    SUBS_ABSTRACT_FACTORY(IShader, UShader, FShaderDesc&);

    SUBS_ABSTRACT_FACTORY(ITransitionBarrier, UTransitionBarrier, FTransitionBarrierDesc&);
  END_FACTORY()
}
