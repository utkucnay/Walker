#pragma once

#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics {

struct WALKER_API FTexture1DDesc {
  EHeapType HeapType = EHeapType::kDefault;
  EResourceFormat ResourceFormat = EResourceFormat::kUNKNOWN;
  u64 Width = 0;
  u16 MipLevels = 0;
  u64 Aligment = 0;
  u16 ArraySize = 1;
  EResourceF ResourceFlag = EResourceF::kNone;
  EResourceLayout ResourceLayout = EResourceLayout::kUnknown;
  EResourceStateF InitialState = EResourceStateF::kCommon;
  FClearValue* ClearValue = nullptr;
};

class WALKER_API UTexture1D {
 public:
  UTexture1D() : m_Resource(nullptr) {}

  explicit UTexture1D(const FTexture1DDesc& texture1DDesc);
  UTexture1D(rhi::IResourceHandle resource);

 public:
  FTexture1DDesc GetDesc();
  b64 IsArray();

  rhi::IResourceHandle GetResource() { return m_Resource; }

 private:
  rhi::IResourceHandle m_Resource;
};

}  // namespace wkr::graphics
