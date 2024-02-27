#include <Platforms/Windows/WindowsWindow.h>
#include <Platforms/Windows/WindowProc.h>

namespace wkr
{
  WindowsWindow::WindowsWindow(const WindowDesc& windowProps)
  {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    std::string className = "Window Class";

    wc.hInstance = hInstance;
    wc.lpfnWndProc = ::WindowProcNative;
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

    WKR_CORE_LOG_COND(NULL == window, "Didn't create window");
    ShowWindow(window, true);
    m_windowMap[window] = this;
  }


  WindowsWindow::~WindowsWindow()
  {
    m_windowMap.erase(window);
  }

  void WindowsWindow::OnUpdate()
  {
  }

  bool WindowsWindow::IsShouldClose()
  {
    return m_isRunning;
  }

  void WindowsWindow::PoolEvents()
  {
    while(PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE))
    {
      TranslateMessage(&message);
      DispatchMessage(&message);
      if(message.message == WM_QUIT) [[unlikely]]
        m_isRunning = false;
    }
  }

  void WindowsWindow::WindowProc(
      UINT uMsg,
      WPARAM wParam, LPARAM lParam)
  {
    switch(uMsg)
    {
      case WM_SIZE:
        m_resizeEvent.Invoke(GetWidth(), GetHeight());
        break;
      case WM_QUIT:
      case WM_DESTROY:
        m_isRunning = false;
        break;
    }
    DefWindowProc(window, uMsg, wParam, lParam);
  }

  bool WindowsWindow::WindowProcHandle(
      HWND hwnd,
      UINT uMsg,
      WPARAM wParam, LPARAM lParam)
  {
    auto window = m_windowMap.find(hwnd);
    if(window == m_windowMap.end()) return false;
    window->second->WindowProc(uMsg, wParam, lParam);
    return true;
  }
}
