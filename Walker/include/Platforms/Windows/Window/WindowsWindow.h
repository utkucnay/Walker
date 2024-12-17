#pragma once

#include "Os/Window/AWindow.h"

LRESULT WindowProcNative(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace wkr::os::windows {

class UWindow : public wkr::os::AWindow {
 public:
  UWindow(FWindowDesc& desc);
  ~UWindow() override;

 public:
  void        OnUpdate()      override;
  b32         IsShouldClose() override;
  void        PoolEvents()    override;
  FWindowDesc GetDesc()       override;

  NativeObject GetNativeObject() override { return &window; }

 private:
  void WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

 public:
  static bool WindowProcHandle(HWND hwnd, UINT uMsg, WPARAM wParam,
                               LPARAM lParam);

 public:
  HWND window{};
  MSG message{};
  WNDCLASS wc{};

 private:
  bool m_isRunning;
  static inline std::unordered_map<HWND, UWindow*> m_windowMap{};

  friend ::LRESULT WindowProcNative(HWND hwnd, UINT uMsg, WPARAM wParam,
                                    LPARAM lParam);
  friend bool WindowProcHandle(HWND hwnd, UINT uMsg, WPARAM wParam,
                               LPARAM lParam);
};

}  // namespace wkr::os::windows
