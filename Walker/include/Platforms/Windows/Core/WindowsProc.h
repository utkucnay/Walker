#pragma once

LRESULT CALLBACK WindowProcNative(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam, LPARAM lParam)
{
  if(wkr::os::windows::UWindow::WindowProcHandle(hwnd, uMsg, wParam, lParam))
    return true;

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
