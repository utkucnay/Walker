#include <Platforms/Windows/WindowsWindow.h>
#include <Platforms/Windows/WindowProc.h>

namespace wkr::os::windows
{
  UWindow::UWindow(FWindowDesc& desc)
  {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    std::string className = "Window Class";

    wc.hInstance = hInstance;
    wc.lpfnWndProc = ::WindowProcNative;
    wc.lpszClassName = className.c_str();

    ShowWindow(GetConsoleWindow(), desc.showCLI);

    RegisterClass(&wc);

    window = CreateWindowEx(
      0,
      className.c_str(),
      desc.m_name.c_str(),
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      desc.m_width,
      desc.m_height,
      NULL,
      NULL,
      hInstance,
      NULL
      );

    WKR_CORE_LOG_COND(NULL == window, "Didn't create window");
    ShowWindow(window, true);
    m_windowMap[window] = this;
  }


  UWindow::~UWindow()
  {
    m_windowMap.erase(window);
  }

  void UWindow::OnUpdate()
  {
  }

  b32 UWindow::IsShouldClose()
  {
    return m_isRunning;
  }

  void UWindow::PoolEvents()
  {
    while(PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE))
    {
      TranslateMessage(&message);
      DispatchMessage(&message);
      if(message.message == WM_QUIT) [[unlikely]]
        m_isRunning = false;
    }
  }

  void UWindow::WindowProc(
      UINT uMsg,
      WPARAM wParam, LPARAM lParam)
  {
    switch(uMsg)
    {
      case WM_SIZE:
        {
          m_resizeEvent(GetWidth(), GetHeight());
        } break;
      case WM_SYSKEYUP:
      case WM_SYSKEYDOWN:
      case WM_KEYUP:
      case WM_KEYDOWN:
        {

        } break;
      case WM_QUIT:
      case WM_DESTROY:
        {
          m_isRunning = false;
        } break;
      default:
        {
          DefWindowProc(window, uMsg, wParam, lParam);
        } break;
    }
  }

  bool UWindow::WindowProcHandle(
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
