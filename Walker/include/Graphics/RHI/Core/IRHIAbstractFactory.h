#pragma once

#include "Core/Factory.h"
#include "Graphics/Graphics.h"

namespace wkr::graphics::rhi {

CREATE_FACTORY_WITH_MARKER(RHI, WALKER_API)

//Core
SUBS_FACTORY(IDevice, FDeviceDesc&)
SUBS_FACTORY(IFence, FFenceDesc&)
SUBS_FACTORY(ASwapChain, FSwapChainDesc&)
SUBS_FACTORY(IRootSignature, FRootSignatureDesc&)
//SUBS_FACTORY(IPipelineState, FPipelineStateDesc&)

//Command
SUBS_FACTORY(ICommandQueue, FCommandQueueDesc&)
SUBS_FACTORY(ICommandList, FCommandListDesc&)
SUBS_FACTORY(ICommandAllocator, FCommandAllocatorDesc&)

//Descriptor
SUBS_FACTORY(IDescriptorHeap, FDescriptorHeapDesc&)

//Resource
SUBS_FACTORY_NAMESPACE(mem, IHeap, FHeapDesc&)
SUBS_FACTORY(IResource, FResourceDesc&)
SUBS_FACTORY(IShader, FShaderDesc&)

//Barriers
SUBS_FACTORY(ITransitionBarrier, FTransitionBarrierDesc&)

END_FACTORY()

}  // namespace wkr::graphics::rhi
