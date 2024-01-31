#pragma once

#include <Core/Window.h>

namespace wkr
{
  LRESULT CALLBACK WindowProc(
      HWND hwnd,
      UINT uMsg,
      WPARAM wParam, LPARAM lParam);

  class WindowsWindow : public Window
  {
  public:
    WindowsWindow(const WindowProps& windowProps);
    ~WindowsWindow();

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

    void* GetNativeHandle() override { return &window; }

  public:
    HWND window{};
    MSG message{};
    WNDCLASS wc = {};

  private:
  friend LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  };
}
