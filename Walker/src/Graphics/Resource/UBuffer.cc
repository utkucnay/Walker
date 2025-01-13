#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

UBuffer::UBuffer(const FBufferDesc& desc) {
  auto& factory = UGraphicsAPI::GetAbstractFactory();

  rhi::FResourceDesc resourceDesc = {
      .DescType = EResourceDescType::kCommitted,
      .HeapProp =
          {
              .Type = desc.HeapType,
              .MemoryPool = EMemoryPool::kUnknown,
              .CpuPageProperty = ECPUPageProperty::kUnknown,
          },
      .HeapFlag = EHeapF::kNone,
      .Resource =
          {
              .Alignment = 0,
              .Width = desc.BufferSize,
              .Height = 1,
              .DepthOrArraySize = 1,
              .MipLevels = 1,
              .Sample =
                  {
                      .Count = 1,
                      .Quality = 0,
                  },
              .Format = EResourceFormat::kUNKNOWN,
              .Flag = desc.ResourceFlag,
              .Layout = EResourceLayout::kRowMajor,
              .Dimension = EResourceDimension::kBuffer,
          },
      .InitialState = desc.InitState,
      .ClearValue = desc.ClearValue,
  };

  m_Resource = rhi::IResourceHandle(factory.GetResource(resourceDesc));
}

UBuffer::UBuffer(rhi::IResourceHandle resource) {
  FResource resourceDesc = resource->GetResourceDesc();
  WKR_CORE_ERROR_COND(resourceDesc.Dimension != EResourceDimension::kBuffer,
                      "Resource isn't a Buffer");

  m_Resource = std::move(resource);
}

FBufferDesc UBuffer::GetDesc() const {
  FResource resourceDesc = m_Resource->GetResourceDesc();
  FHeapProperties heapProp = m_Resource->GetHeapProperties();

  FBufferDesc bufferDesc = {
      .HeapType = heapProp.Type,
      .BufferSize = resourceDesc.Width,
      .InitState = EResourceStateF::kCommon,
      .ClearValue = nullptr,
      .ResourceFlag = resourceDesc.Flag,
  };

  return bufferDesc;
}

}  // namespace wkr::graphics
