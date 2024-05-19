#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Core/AbstractFactory.h>

namespace wkr::render
{
  //Core
  REGISTER_FACTORY(IDevice,        UDX12Device,     DeviceBuilder&);
  REGISTER_FACTORY(IFence,         UDX12Fence,      FenceBuilder&);
  REGISTER_FACTORY(USwapChain,     UDX12SwapChain,  SwapChainBuilder&);
  //REGISTER_FACTORY(PipelineState, DX12PipelineState);
  REGISTER_FACTORY(IRootSignature, UDX12RootSignature, RootSignatureBuilder&);

  //Command
  REGISTER_FACTORY(ICommandQueue,      UDX12CommandQueue,     CommandQueueBuilder&);
  REGISTER_FACTORY(ICommandList,       UDX12CommandList,      CommandListBuilder&);
  REGISTER_FACTORY(ICommandAllocator,  UDX12CommandAllocator, CommandAllocatorBuilder&);

  //Descriptor
  REGISTER_FACTORY(IDescriptorHeap, UDX12DescriptorHeap, DescriptorHeapBuilder&);

  //Resource
  namespace rsc
  {
    REGISTER_FACTORY(IHeap    , UDX12Heap   , HeapBuilder&);
    REGISTER_FACTORY(IBuffers , UDX12Buffers, ResourceBuilder<IBuffers>&);
  //REGISTER_FACTORY(rsc::Texture1D,      rsc::DX12Texture1D);
  //REGISTER_FACTORY(rsc::Texture1DArray, rsc::DX12Texture1DArray);
  //REGISTER_FACTORY(Texture2D,      DX12Texture2D);
  //REGISTER_FACTORY(rsc::Texture2DArray, rsc::DX12Texture2DArray);
  //REGISTER_FACTORY(rsc::Texture3D,      rsc::DX12Texture3D);
    namespace bar
    {
      REGISTER_FACTORY(
          ITransitionBarrier,
          UDX12TransitionBarrier,
          TransitionBarrierBuilder&);
    }
  }


  class DX12AbstractFactory : public AbstractFactory
  {
  public:
    DX12AbstractFactory() { UDX12Factory::Init(); }

    //Core
    mem::Scope<IFactory<IDevice, DeviceBuilder&>>
      GetDeviceFactory() { return mem::Scope<UDX12DeviceFactory>::Create(); }
    mem::Scope<IFactory<IFence, FenceBuilder&>>
      GetFenceFactory() { return mem::Scope<UDX12FenceFactory>::Create(); }
    mem::Scope<IFactory<USwapChain, SwapChainBuilder&>>
      GetSwapChainFactory() { return mem::Scope<UDX12SwapChainFactory>::Create(); }
    //mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory();
    mem::Scope<IFactory<IRootSignature, RootSignatureBuilder&>>
      GetRootSignatureFactory() { return mem::Scope<UDX12RootSignatureFactory>::Create(); };

    //Command
    mem::Scope<IFactory<ICommandQueue, CommandQueueBuilder&>>
      GetCommandQueueFactory() { return mem::Scope<UDX12CommandQueueFactory>::Create(); }
    mem::Scope<IFactory<ICommandList, CommandListBuilder&>>
      GetCommandListFactory() { return mem::Scope<UDX12CommandListFactory>::Create(); }
    mem::Scope<IFactory<ICommandAllocator, CommandAllocatorBuilder&>>
      GetCommandAllocatorFactory() { return mem::Scope<UDX12CommandAllocatorFactory>::Create(); }

    //Descriptor
    mem::Scope<IFactory<IDescriptorHeap, DescriptorHeapBuilder&>>
      GetDescriptorHeapFactory() { return mem::Scope<UDX12DescriptorHeapFactory>::Create(); }

    //Resource
    virtual mem::Scope<IFactory<rsc::IHeap, rsc::HeapBuilder&>>
      GetHeapFactory()
    { return mem::Scope<rsc::UDX12HeapFactory>::Create(); }
    mem::Scope<IFactory<rsc::IBuffers, rsc::ResourceBuilder<rsc::IBuffers>&>>
      GetBuffersFactory()
    { return mem::Scope<rsc::UDX12BuffersFactory>::Create();}
    //mem::Scope<Factory<rsc::Texture1D>> GetTexture1DFactory();
    //mem::Scope<Factory<rsc::Texture2D>> GetTexture2DFactory();
    //mem::Scope<Factory<rsc::Texture3D>> GetTexture3DFactory();

    //mem::Scope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory();
    //mem::Scope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory();

    //Resource Barrier
    virtual mem::Scope<IFactory<rsc::bar::ITransitionBarrier, rsc::bar::TransitionBarrierBuilder&>>
      GetTransitionBarrierFactory() {
        return mem::Scope<rsc::bar::UDX12TransitionBarrierFactory>::Create();}
  };
}
