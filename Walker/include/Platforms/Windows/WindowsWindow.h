#pragma once

#include <Core/Window.h>

LRESULT WindowProcNative(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace wkr
{
  class WindowsWindow : public Window
  {
  public:
    WindowsWindow(const WindowDesc& windowProps);
    ~WindowsWindow() override;

  public:
    void OnUpdate() override;
    bool IsShouldClose() override;
    void PoolEvents() override;

    int GetWidth() override
    {
      RECT rect;
      if(GetWindowRect(window, &rect))
      {
        return rect.right - rect.left;
      }
      return 0;
    }

    int GetHeight() override
    {
      RECT rect;
      if(GetWindowRect(window, &rect))
      {
        return rect.bottom - rect.top;
      }
      return 0;
    }

    bool GetWindowed() override
    {
      LONG wLong =  GetWindowLong(window, 0);

      return (wLong & WS_POPUP) == 0;
    }

    void* GetNativeHandle() override { return &window; }

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
    static inline std::unordered_map<HWND, WindowsWindow*> m_windowMap{};

    friend :: LRESULT WindowProcNative(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    friend bool WindowProcHandle(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  };
}
