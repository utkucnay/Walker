#pragma once

namespace wkr::os {

struct WALKER_API FWindowDesc {
  u32 Width = 0;
  u32 Height = 0;
  b32 ShowCLI = false;
  b32 Windowed = false;
  std::string_view Name = {};
};

class WALKER_API AWindow {
 public:
  virtual ~AWindow() = default;

 public:
  virtual void OnUpdate() = 0;
  virtual b32 IsShouldClose() = 0;
  virtual void PoolEvents() = 0;

  virtual FWindowDesc GetDesc() = 0;
  virtual NativeObject GetNativeObject() = 0;

 public:
  WindowResizeEvent ResizeEvent;
  WindowSetFullscreenEvent SetFullscreenEvent;
};

using AWindowHandle = wkr::mem::TRef<AWindow>;

}  // namespace wkr::os
