#pragma once

#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics::rsc {

struct WALKER_API FTexture2DDesc {
  EHeapType heapType = EHeapType::kDefault;
  EResourceFormat resourceFormat = EResourceFormat::kUNKNOWN;
  u64 width = 0;
  u32 height = 0;
  FSample sample = {0, 0};
  EResourceF resourceFlag = EResourceF::kNone;
  EResourceLayout resourceLayout = EResourceLayout::kUnknown;
  EResourceStateF initialState = EResourceStateF::kCommon;
  FClearValue* clearValue = nullptr;
};

class WALKER_API UTexture2D {
 public:
  UTexture2D(const FTexture2DDesc& texture2DDesc);

 public:
  FTexture2DDesc GetDesc() const;
  IResourceHandle GetResource() { return m_Resource; }

 private:
  IResourceHandle m_Resource;
};

}  // namespace wkr::graphics::rsc
