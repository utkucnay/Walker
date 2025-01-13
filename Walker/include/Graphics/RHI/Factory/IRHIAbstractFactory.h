#pragma once

#include "Graphics/RHI/RHI.h"

namespace wkr::graphics::rhi {

class IRHIAbstractFactory {
 public:
  virtual ~IRHIAbstractFactory() = default;

 public:
  virtual IDevice* GetDevice(const FDeviceDesc&) = 0;
  virtual AFence* GetFence(const FFenceDesc&) = 0;
  virtual ASwapChain* GetSwapChain(const FSwapChainDesc&) = 0;
  virtual IRootSignature* GetRootSignature(const FRootSignatureDesc&) = 0;
  //virtual IPipelineState* GetPipelineState(const FPipelineStateDesc&) = 0;

  virtual ICommandQueue* GetCommandQueue(const FCommandQueueDesc&) = 0;
  virtual ICommandList* GetCommandList(const FCommandListDesc&) = 0;
  virtual ICommandAllocator* GetCommandAllocator(
      const FCommandAllocatorDesc&) = 0;

  virtual ADescriptorHeap* GetDescriptorHeap(const FDescriptorHeapDesc&) = 0;

  virtual IHeap* GetHeap(const FHeapDesc&) = 0;

  virtual IResource* GetResource(const FResourceDesc&) = 0;
  virtual IResourceBarrier* GetResourceBarrier(const FResourceBarrierDesc&) = 0;

  virtual IShader* GetShader(const FShaderDesc&) = 0;
};

}  // namespace wkr::graphics::rhi
