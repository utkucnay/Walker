#include "Graphics/Resource/UTexture2D.h"
#include "Core/Base.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

UTexture2D::UTexture2D(const FTexture2DDesc& desc) {
  auto resourceFactory = UGraphicsAPI::GetAbstractFactory().GetIResource();

  rhi::FResourceDesc resourceDesc = {
      .DescType = EResourceDescType::kCommitted,
      .HeapProp =
          {

          },
      .HeapFlag = EHeapF::kNone,
      .Resource =
          {
              .Alignment = 0,
              .Width = desc.Width,
              .Height = desc.Height,
              .DepthOrArraySize = 1,
              .MipLevels = 1,
              .Sample =
                  {
                      .Count = 1,
                      .Quality = 0,
                  },
              .Format = desc.ResourceFormat,
              .Flag = desc.ResourceFlag,
              .Layout = desc.ResourceLayout,
              .Dimension = EResourceDimension::kTexture2D,
          },
      .InitialState = desc.InitialState,
      .ClearValue = desc.ClearValue,
  };

  m_Resource = resourceFactory->Create(resourceDesc);
}

UTexture2D::UTexture2D(rhi::IResourceHandle resourceHandle) {
  WKR_CORE_ERROR_COND(resourceHandle->GetDesc().Dimension !=
                          EResourceDimension::kTexture2D,
                      "Not Match Dimension");

  m_Resource = std::move(resourceHandle);
}

FTexture2DDesc UTexture2D::GetDesc() {
  FResource desc = m_Resource->GetDesc();

  //TODO(utku): FIX this
  FTexture2DDesc retDesc = {
    .HeapType = {},
    .ResourceFormat = desc.Format,
    .Width = desc.Width,
    .Height = desc.Height,
    .Sample = desc.Sample,
    .ResourceFlag = desc.Flag,
    .ResourceLayout = desc.Layout,
    .InitialState = {},
    .ClearValue = {},
  };

  return retDesc;
}

}  // namespace wkr::graphics
