#pragma once

#include "Graphics/RHI/RHI.h"

namespace wkr::graphics::rhi {

CREATE_FACTORY_WITH_MARKER(RHI, WALKER_API)

//Core
SUBS_FACTORY(IDevice, FDeviceDesc&)
SUBS_FACTORY(AFence, FFenceDesc&)
SUBS_FACTORY(ASwapChain, FSwapChainDesc&)
SUBS_FACTORY(IRootSignature, FRootSignatureDesc&)
//SUBS_FACTORY(IPipelineState, FPipelineStateDesc&)

//Command
SUBS_FACTORY(ICommandQueue, FCommandQueueDesc&)
SUBS_FACTORY(ICommandList, FCommandListDesc&)
SUBS_FACTORY(ICommandAllocator, FCommandAllocatorDesc&)

//Descriptor
SUBS_FACTORY(ADescriptorHeap, FDescriptorHeapDesc&)

//Resource
SUBS_FACTORY(IHeap, FHeapDesc&)
SUBS_FACTORY(IResource, FResourceDesc&)
SUBS_FACTORY(IShader, FShaderDesc&)
SUBS_FACTORY(IResourceBarrier, FResourceBarrierDesc&)

END_FACTORY()

using IRHIAbstractFactoryHandle = mem::TRef<IRHIAbstractFactory>;

}  // namespace wkr::graphics::rhi
