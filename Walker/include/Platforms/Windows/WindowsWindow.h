#pragma once

#include <Core/Window.h>

LRESULT WindowProcNative(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace wkr
{
  class UWindowsWindow : public UWindow
  {
  public:
    UWindowsWindow(WindowBuilder& windowBuilder);
    ~UWindowsWindow() override;

  public:
    void OnUpdate() override;
    b32 IsShouldClose() override;
    void PoolEvents() override;

    u32 GetWidth() override
    {
      RECT rect;
      if(GetWindowRect(window, &rect))
      {
        return rect.right - rect.left;
      }
      return 0;
    }

    u32 GetHeight() override
    {
      RECT rect;
      if(GetWindowRect(window, &rect))
      {
        return rect.bottom - rect.top;
      }
      return 0;
    }

    b32 GetWindowed() override
    {
      LONG wLong =  GetWindowLong(window, 0);

      return (wLong & WS_POPUP) == 0;
    }

    NativeHandle GetNativeHandle() override { return &window; }

  private:
    void WindowProc(
        UINT uMsg,
        WPARAM wParam, LPARAM lParam);

  public:
    static bool WindowProcHandle(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam, LPARAM lParam);

  public:
    HWND window{};
    MSG message{};
    WNDCLASS wc = {};

  private:
    bool m_isRunning;
    static inline std::unordered_map<HWND, UWindowsWindow*> m_windowMap{};

    friend :: LRESULT WindowProcNative(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    friend bool WindowProcHandle(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  };
}
