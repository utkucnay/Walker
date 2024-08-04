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
  REGISTER_FACTORY(IBuffers, UBuffers, FBuffersDesc&);
  //REGISTER_FACTORY(rsc::Texture1D,      rsc::DX12Texture1D);
  //REGISTER_FACTORY(rsc::Texture1DArray, rsc::DX12Texture1DArray);
  //REGISTER_FACTORY(Texture2D,      DX12Texture2D);
  //REGISTER_FACTORY(rsc::Texture2DArray, rsc::DX12Texture2DArray);
  //REGISTER_FACTORY(rsc::Texture3D,      rsc::DX12Texture3D);
  REGISTER_FACTORY(ITransitionBarrier, UTransitionBarrier, FTransitionBarrierDesc&);

  BEGIN_FACTORY()
    CTOR_FACTORY(UDX12Factory::Init();)

    //Core
    SUBS_FACTORY(IDevice, UDevice, FDeviceDesc&);
    SUBS_FACTORY(IFence, UFence, FFenceDesc&);
    SUBS_FACTORY(ASwapChain, USwapChain, FSwapChainDesc&);
    SUBS_FACTORY(IRootSignature, URootSignature, FRootSignatureDesc&);

    //Command
    SUBS_FACTORY(ICommandQueue, UCommandQueue, FCommandQueueDesc&);
    SUBS_FACTORY(ICommandList, UCommandList, FCommandListDesc&);
    SUBS_FACTORY(ICommandAllocator, UCommandAllocator, FCommandAllocatorDesc&);

    //Descriptor
    SUBS_FACTORY(IDescriptorHeap, UDescriptorHeap, FDescriptorHeapDesc&);

    //Resource
    SUBS_FACTORY(IHeap , UHeap, FHeapDesc&);
    SUBS_FACTORY(IBuffers, UBuffers, FBuffersDesc&);
    SUBS_FACTORY(ITransitionBarrier, UTransitionBarrier, FTransitionBarrierDesc&);
  END_FACTORY()
}
