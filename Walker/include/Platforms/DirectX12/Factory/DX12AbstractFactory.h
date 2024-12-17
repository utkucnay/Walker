#pragma once

#include "Graphics/RHI/Factory/IRHIAbstractFactory.h"
#include "Platforms/DirectX12/DX12.h"

namespace wkr::graphics::rhi::dx12 {

//Core
REGISTER_FACTORY(IDevice, UDevice, FDeviceDesc&);
REGISTER_FACTORY(AFence, UFence, FFenceDesc&);
REGISTER_FACTORY(ASwapChain, USwapChain, FSwapChainDesc&);
//REGISTER_FACTORY(IPipelineState, UPipelineState, FPipelineStateDesc&);
REGISTER_FACTORY(IRootSignature, URootSignature, FRootSignatureDesc&);

//Command
REGISTER_FACTORY(ICommandQueue, UCommandQueue, FCommandQueueDesc&);
REGISTER_FACTORY(ICommandList, UCommandList, FCommandListDesc&);
REGISTER_FACTORY(ICommandAllocator, UCommandAllocator, FCommandAllocatorDesc&);

//Descriptor
REGISTER_FACTORY(ADescriptorHeap, UDescriptorHeap, FDescriptorHeapDesc&);

//Resource
REGISTER_FACTORY(IHeap, UHeap, FHeapDesc&);
REGISTER_FACTORY(IResource, UResource, FResourceDesc&);
REGISTER_FACTORY(IShader, UShader, FShaderDesc&);

REGISTER_FACTORY(IResourceBarrier, UResourceBarrier, FResourceBarrierDesc&);

BEGIN_ABSTRACT_FACTORY(RHI)

CTOR_ABSTRACT_FACTORY(RHI, UDX12Factory::Init();)

//Core
SUBS_ABSTRACT_FACTORY(IDevice, UDevice, FDeviceDesc&);
SUBS_ABSTRACT_FACTORY(AFence, UFence, FFenceDesc&);
SUBS_ABSTRACT_FACTORY(ASwapChain, USwapChain, FSwapChainDesc&);
SUBS_ABSTRACT_FACTORY(IRootSignature, URootSignature, FRootSignatureDesc&);

//Command
SUBS_ABSTRACT_FACTORY(ICommandQueue, UCommandQueue, FCommandQueueDesc&);
SUBS_ABSTRACT_FACTORY(ICommandList, UCommandList, FCommandListDesc&);
SUBS_ABSTRACT_FACTORY(ICommandAllocator, UCommandAllocator,
                      FCommandAllocatorDesc&);

//Descriptor
SUBS_ABSTRACT_FACTORY(ADescriptorHeap, UDescriptorHeap, FDescriptorHeapDesc&);

//Resource
SUBS_ABSTRACT_FACTORY(IHeap, UHeap, FHeapDesc&);
SUBS_ABSTRACT_FACTORY(IResource, UResource, FResourceDesc&);
SUBS_ABSTRACT_FACTORY(IShader, UShader, FShaderDesc&);

SUBS_ABSTRACT_FACTORY(IResourceBarrier, UResourceBarrier,
                      FResourceBarrierDesc&);
END_FACTORY()

}  // namespace wkr::graphics::rhi::dx12
