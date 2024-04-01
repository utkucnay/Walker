#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Core/AbstractFactory.h>

namespace wkr::render
{
  //Core
  REGISTER_FACTORY(Device,        DX12Device,     DeviceBuilder*);
  REGISTER_FACTORY(Fence,         DX12Fence,      FenceBuilder*);
  REGISTER_FACTORY(SwapChain,     DX12SwapChain,  SwapChainBuilder*);
  //REGISTER_FACTORY(PipelineState, DX12PipelineState);
  //REGISTER_FACTORY(RootSignature, DX12RootSignature);

  //Command
  REGISTER_FACTORY(CommandQueue,      DX12CommandQueue,     CommandQueueBuilder*);
  REGISTER_FACTORY(CommandList,       DX12CommandList,      CommandListBuilder*);
  REGISTER_FACTORY(CommandAllocator,  DX12CommandAllocator, CommandAllocatorBuilder*);

  //Descriptor
  REGISTER_FACTORY(DescriptorHeap, DX12DescriptorHeap, DescriptorHeapBuilder*);

  //Resource
  namespace rsc
  {
    REGISTER_FACTORY(Heap, DX12Heap, HeapBuilder*);
    REGISTER_FACTORY(Buffers, DX12Buffers, ResourceBuilder<Buffers>*);
  //REGISTER_FACTORY(rsc::Texture1D,      rsc::DX12Texture1D);
  //REGISTER_FACTORY(rsc::Texture1DArray, rsc::DX12Texture1DArray);
  //REGISTER_FACTORY(Texture2D,      DX12Texture2D);
  //REGISTER_FACTORY(rsc::Texture2DArray, rsc::DX12Texture2DArray);
  //REGISTER_FACTORY(rsc::Texture3D,      rsc::DX12Texture3D);
    namespace bar
    {
      REGISTER_FACTORY(
          TransitionBarrier,
          DX12TransitionBarrier,
          TransitionBarrierBuilder*);
    }
  }


  class DX12AbstractFactory : public AbstractFactory
  {
  public:
    DX12AbstractFactory() { DX12Factory::Init(); }

    //Core
    mem::Scope<Factory<Device, DeviceBuilder*>>
      GetDeviceFactory() { return mem::Scope<DX12DeviceFactory>::Create(); }
    mem::Scope<Factory<Fence, FenceBuilder*>>
      GetFenceFactory() { return mem::Scope<DX12FenceFactory>::Create(); }
    mem::Scope<Factory<SwapChain, SwapChainBuilder*>>
      GetSwapChainFactory() { return mem::Scope<DX12SwapChainFactory>::Create(); }
    //mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory();
    //mem::Scope<Factory<RootSignature>>  GetRootSignatureFactory();

    //Command
    mem::Scope<Factory<CommandQueue, CommandQueueBuilder*>>
      GetCommandQueueFactory() { return mem::Scope<DX12CommandQueueFactory>::Create(); }
    mem::Scope<Factory<CommandList, CommandListBuilder*>>
      GetCommandListFactory() { return mem::Scope<DX12CommandListFactory>::Create(); }
    mem::Scope<Factory<CommandAllocator, CommandAllocatorBuilder*>>
      GetCommandAllocaterFactory() { return mem::Scope<DX12CommandAllocatorFactory>::Create(); }

    //Descriptor
    mem::Scope<Factory<DescriptorHeap, DescriptorHeapBuilder*>>
      GetDescriptorHeapFactory() { return mem::Scope<DX12DescriptorHeapFactory>::Create(); }

    //Resource
    virtual mem::Scope<Factory<rsc::Heap, rsc::HeapBuilder*>>
      GetHeapFactory()
    { return mem::Scope<rsc::DX12HeapFactory>::Create(); }
    mem::Scope<Factory<rsc::Buffers, rsc::ResourceBuilder<rsc::Buffers>*>>
      GetBuffersFactory()
    { return mem::Scope<rsc::DX12BuffersFactory>::Create();}
    //mem::Scope<Factory<rsc::Texture1D>> GetTexture1DFactory();
    //mem::Scope<Factory<rsc::Texture2D>> GetTexture2DFactory();
    //mem::Scope<Factory<rsc::Texture3D>> GetTexture3DFactory();

    //mem::Scope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory();
    //mem::Scope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory();

    //Resource Barrier
    virtual mem::Scope<Factory<rsc::bar::TransitionBarrier, rsc::bar::TransitionBarrierBuilder*>>
      GetResourceBarrierTransition() {
        return mem::Scope<rsc::bar::DX12TransitionBarrierFactory>::Create();}
  };
}
