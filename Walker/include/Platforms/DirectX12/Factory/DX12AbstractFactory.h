#pragma once

#include "Graphics/RHI/Factory/IRHIAbstractFactory.h"
#include "Platforms/DirectX12/Core/DX12Factory.h"
#include "Platforms/DirectX12/DX12.h"

namespace wkr::graphics::rhi::dx12 {

class URHIAbstractFactory : public IRHIAbstractFactory {
 public:
  URHIAbstractFactory() { UDX12Factory::Init(); }

  ~URHIAbstractFactory() override { UDX12Factory::Destroy(); }

 public:
  IDevice* GetDevice(const FDeviceDesc& desc) override final {
    return new UDevice(desc);
  }

  AFence* GetFence(const FFenceDesc& desc) override final {
    return new UFence(desc);
  }

  ASwapChain* GetSwapChain(const FSwapChainDesc& desc) override final {
    return new USwapChain(desc);
  }

  IRootSignature* GetRootSignature(
      const FRootSignatureDesc& desc) override final {
    return new URootSignature(desc);
  }

  ICommandQueue* GetCommandQueue(const FCommandQueueDesc& desc) override final {
    return new UCommandQueue(desc);
  }

  ICommandList* GetCommandList(const FCommandListDesc& desc) override final {
    return new UCommandList(desc);
  }

  ICommandAllocator* GetCommandAllocator(
      const FCommandAllocatorDesc& desc) override final {
    return new UCommandAllocator(desc);
  }

  ADescriptorHeap* GetDescriptorHeap(
      const FDescriptorHeapDesc& desc) override final {
    return new UDescriptorHeap(desc);
  }

  IHeap* GetHeap(const FHeapDesc& desc) override final {
    return new UHeap(desc);
  }

  IResource* GetResource(const FResourceDesc& desc) override final {
    return new UResource(desc);
  }

  IResourceBarrier* GetResourceBarrier(
      const FResourceBarrierDesc& desc) override final {
    return new UResourceBarrier(desc);
  }

  IShader* GetShader(const FShaderDesc& desc) override final {
    return new UShader(desc);
  }
};

}  // namespace wkr::graphics::rhi::dx12
