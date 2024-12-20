#include "Graphics/Resource/UTexture1D.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

UTexture1D::UTexture1D(const FTexture1DDesc& texture1DDesc) {

  rhi::FResourceDesc resourceDesc = {
      .DescType = EResourceDescType::kCommitted,
      .HeapProp =
          {
              .Type = texture1DDesc.HeapType,
              .MemoryPool = EMemoryPool::kUnknown,
              .CpuPageProperty = ECPUPageProperty::kUnknown,
          },
      .HeapFlag = EHeapF::kNone,
      .Resource =
          {
              .Alignment = texture1DDesc.Aligment,
              .Width = texture1DDesc.Width,
              .Height = 1,
              .DepthOrArraySize = 1,
              .MipLevels = texture1DDesc.MipLevels,
              .Sample =
                  {
                      .Count = 1,
                      .Quality = 0,
                  },
              .Format = texture1DDesc.ResourceFormat,
              .Flag = texture1DDesc.ResourceFlag,
              .Layout = texture1DDesc.ResourceLayout,
              .Dimension = EResourceDimension::kTexture1D,
          },
      .InitialState = EResourceStateF::kCommon,
      .ClearValue = texture1DDesc.ClearValue,
  };

  auto& factory = UGraphicsAPI::GetAbstractFactory();

  m_Resource = rhi::IResourceHandle(factory.GetIResource()->Create(resourceDesc));
}

UTexture1D::UTexture1D(rhi::IResourceHandle resource) {
  FResource resourceDesc = resource->GetResourceDesc();

  WKR_CORE_ERROR_COND(resourceDesc.Dimension != EResourceDimension::kTexture1D,
      "Dimension Not Match");

  WKR_CORE_ERROR_COND(resourceDesc.DepthOrArraySize != 1,
      "It's a Array Type");

  m_Resource = std::move(resource);
}

FTexture1DDesc UTexture1D::GetDesc() {
  FResource resourceDesc = m_Resource->GetResourceDesc();
  FHeapProperties heapProp = m_Resource->GetHeapProperties();

  FTexture1DDesc retDesc = {
    .HeapType = heapProp.Type,
    .ResourceFormat = resourceDesc.Format,
    .Width = resourceDesc.Width,
    .MipLevels = resourceDesc.MipLevels,
    .Aligment = resourceDesc.Alignment,
    .ResourceFlag = resourceDesc.Flag,
    .ResourceLayout = resourceDesc.Layout,
    .InitialState = EResourceStateF::kCommon,
    .ClearValue = nullptr,
  };

  return retDesc;
}

b64 UTexture1D::IsArray() {
  FResource resource = m_Resource->GetResourceDesc();
  return resource.DepthOrArraySize > 1;
}

}  // namespace wkr::graphics
