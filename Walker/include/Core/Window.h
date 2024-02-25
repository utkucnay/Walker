#pragma once

namespace wkr
{
  struct WindowProps
  {
    std::string name;
    uint32_t width, height;
  };

  class Window
  {
  public:
    virtual ~Window() = 0;

  public:
    virtual void OnUpdate() = 0;
    virtual bool IsShouldClose() = 0;
    virtual void PoolEvents() = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;
    virtual bool GetWindowed() = 0;

    virtual void* GetNativeHandle() = 0;
  };

  class WindowBuilder : Builder<Window>
  {

  };
}
