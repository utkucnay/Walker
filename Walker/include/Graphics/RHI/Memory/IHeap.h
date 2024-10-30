#pragma once

#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FHeapDesc {
  u64 Size = 0;
  u64 Alignment = 0;
  EHeapType Type = EHeapType::kDefault;
  EMemoryPool MemoryPool = EMemoryPool::kUnknown;
  ECPUPageProperty CpuPageProperty = ECPUPageProperty::kUnknown;
  EHeapF Flag = EHeapF::kNone;
};

class WALKER_API IHeap {
 public:
  virtual ~IHeap() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;
  virtual FHeapDesc GetDesc() = 0;
};

using IHeapHandle = wkr::mem::TRef<IHeap>;

}  // namespace wkr::graphics::rhi
