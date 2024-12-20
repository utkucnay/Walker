#pragma once

#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics {

struct WALKER_API FTexture3DDesc {
  EHeapType HeapType = EHeapType::kDefault;
  EResourceFormat ResourceFormat = EResourceFormat::kUNKNOWN;
  u64 Width = 0;
  u32 Height = 0;
  u64 Alignment = 0;
  u16 MipLevels = 0;
  u16 DepthSize = 1;
  EResourceF ResourceFlag = EResourceF::kNone;
  EResourceLayout ResourceLayout = EResourceLayout::kUnknown;
  EResourceStateF InitialState = EResourceStateF::kCommon;
  FClearValue* ClearValue = nullptr;
};

class WALKER_API UTexture3D {
 public:
  UTexture3D() : m_Resource(nullptr) {}

  explicit UTexture3D(const FTexture3DDesc& desc);
  UTexture3D(rhi::IResourceHandle resource);

 public:
  FTexture3DDesc GetDesc();

  rhi::IResourceHandle GetResource() { return m_Resource; }

 private:
  rhi::IResourceHandle m_Resource;
};

}  // namespace wkr::graphics
