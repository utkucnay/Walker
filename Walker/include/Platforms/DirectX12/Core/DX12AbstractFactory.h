#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Core/AbstractFactory.h>

namespace wkr::render
{
  //Core
  REGISTER_FACTORY(Fence,         DX12Fence);
  REGISTER_FACTORY(SwapChain,     DX12SwapChain);
  REGISTER_FACTORY(PipelineState, DX12PipelineState);
  REGISTER_FACTORY(RootSignature, DX12RootSignature);

  //Command
  REGISTER_FACTORY(CommandQueue,      DX12CommandQueue);
  REGISTER_FACTORY(CommandList,       DX12CommandList);
  REGISTER_FACTORY(CommandAllocator,  DX12CommandAllocator);

  //Descriptor
  REGISTER_FACTORY(DescriptorHeap, DX12DescriptorHeap);

  //Resource
  REGISTER_FACTORY(rsc::Buffers,        rsc::DX12Buffers);
  REGISTER_FACTORY(rsc::Texture1D,      rsc::DX12Texture1D);
  REGISTER_FACTORY(rsc::Texture1DArray, rsc::DX12Texture1DArray);
  REGISTER_FACTORY(rsc::Texture2D,      rsc::DX12Texture2D);
  REGISTER_FACTORY(rsc::Texture2DArray, rsc::DX12Texture2DArray);
  REGISTER_FACTORY(rsc::Texture3D,      rsc::DX12Texture3D);

  class DX12AbstractFactory : public AbstractFactory
  {
  public:
    //Core
    mem::Scope<Factory<Fence>>          GetFenceFactory();
    mem::Scope<Factory<SwapChain>>      GetSwapChainFactory();
    mem::Scope<Factory<PipelineState>>  GetPipelineStateFactory();
    mem::Scope<Factory<RootSignature>>  GetRootSignatureFactory();

    //Command
    mem::Scope<Factory<CommandQueue>>     GetCommandQueueFactory();
    mem::Scope<Factory<CommandList>>      GetCommandListFactory();
    mem::Scope<Factory<CommandAllocator>> GetCommandAllocaterFactory();

    //Descriptor
    mem::Scope<Factory<DescriptorHeap>> GetDescriptorHeapFactory();

    //Resource
    mem::Scope<Factory<rsc::Buffers>>   GetBufferFactory();
    mem::Scope<Factory<rsc::Texture1D>> GetTexture1DFactory();
    mem::Scope<Factory<rsc::Texture2D>> GetTexture2DFactory();
    mem::Scope<Factory<rsc::Texture3D>> GetTexture3DFactory();

    mem::Scope<Factory<rsc::Texture1DArray>> GetTexture1DArrayFactory();
    mem::Scope<Factory<rsc::Texture2DArray>> GetTexture2DArrayFactory();

  };
}
