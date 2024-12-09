#pragma once

#include "Graphics/RHI/Memory/IHeap.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FResourceDesc {
  EResourceDescType DescType = EResourceDescType::kCommitted;

  union {
    FHeapDesc HeapDesc;

    struct {
      IHeap* Heap = nullptr;
      u64 HeapOffset = 0;
    };
  };

  FResource Resource = {};
  EResourceStateF InitialState = EResourceStateF::kCommon;
  FClearValue* ClearValue = nullptr;
};

class WALKER_API IResource {
 public:
  virtual ~IResource() = default;

 public:
  virtual FResourceDesc GetDesc() = 0;
  virtual NativeObject GetNativeObject() = 0;
};

using IResourceHandle = wkr::mem::TRef<IResource>;

}  // namespace wkr::graphics::rhi
