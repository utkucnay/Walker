#include <Platforms/Windows/WindowsWindow.h>

namespace wkr
{
  LRESULT CALLBACK WindowProc(
      HWND hwnd,
      UINT uMsg,
      WPARAM wParam, LPARAM lParam)
  {
    switch (uMsg) {
      case WM_QUIT:
        {
        } break;
      case WM_DESTROY:
        {
          PostQuitMessage(0);
        } break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }

  WindowsWindow::WindowsWindow(const WindowProps& windowProps)
  {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    std::string className = "Window Class";

    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = className.c_str();

    RegisterClass(&wc);

    window = CreateWindowEx(
      0,
      className.c_str(),
      windowProps.name.c_str(),
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      windowProps.width,
      windowProps.height,
      NULL,
      NULL,
      hInstance,
      NULL
      );

    if(window == NULL)
    {
      //TODO(utku): correct loging
      std::cout << "Didn't create window" << "\n";
    }

    ShowWindow(window, true);
  }


  WindowsWindow::~WindowsWindow()
  {

  }

  void WindowsWindow::OnUpdate()
  {

  }

  bool WindowsWindow::IsShouldClose()
  {
    return message.message != WM_QUIT;
  }

  void WindowsWindow::PoolEvents()
  {
    while(PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE))
    {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
  }
}
