#pragma once

namespace wkr
{
  struct WindowProps
  {
    std::string name;
    int width, height;
  };

  class Window
  {
  public:
    virtual void OnUpdate() = 0;
    virtual bool IsShouldClose() = 0;
    virtual void PoolEvents() = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;

    virtual void* GetNativeHandle() = 0;
  };
}
