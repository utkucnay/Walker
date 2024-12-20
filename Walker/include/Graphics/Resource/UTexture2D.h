#pragma once

#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics {

struct WALKER_API FTexture2DDesc {
  EHeapType HeapType = EHeapType::kDefault;
  EResourceFormat ResourceFormat = EResourceFormat::kUNKNOWN;
  u64 Width = 0;
  u32 Height = 0;
  u64 Alignment = 0;
  u16 MipLevels = 0;
  u16 ArraySize = 1;
  FSample Sample = {
      .Count = 1,
      .Quality = 0,
  };
  EResourceF ResourceFlag = EResourceF::kNone;
  EResourceLayout ResourceLayout = EResourceLayout::kUnknown;
  EResourceStateF InitialState = EResourceStateF::kCommon;
  FClearValue* ClearValue = nullptr;
};

class WALKER_API UTexture2D {
 public:
  UTexture2D() : m_Resource(nullptr) {}

  explicit UTexture2D(const FTexture2DDesc& desc);
  UTexture2D(rhi::IResourceHandle resource);

 public:
  FTexture2DDesc GetDesc();
  b64 HasMSAA();
  b64 IsArray();

  rhi::IResourceHandle GetResource() { return m_Resource; }

 private:
  rhi::IResourceHandle m_Resource;
};

}  // namespace wkr::graphics
