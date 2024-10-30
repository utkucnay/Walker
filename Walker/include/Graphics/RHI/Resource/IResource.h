#pragma once

#include "Graphics/RHI/Memory/IHeap.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

struct WALKER_API FResourceDesc {
  EResourceDescType descType = EResourceDescType::kCommitted;

  union {
    mem::FHeapDesc heapDesc;

    struct {
      mem::IHeap* heap = nullptr;
      u64 heapOffset = 0;
    };
  };

  FResource resource = {};
  EResourceStateF initialState = EResourceStateF::kCommon;
  FClearValue* clearValue = nullptr;
};

class WALKER_API IResource {
 public:
  virtual ~IResource() = default;

 public:
  virtual FResourceDesc GetDesc() = 0;
  virtual NativeObject GetNativeObject() = 0;
};

using IResourceHandle = wkr::mem::TRef<IResource>;

}  // namespace wkr::graphics
