#include <Core/Window.h>

namespace wkr
{
  void UWindow::SwapBuffers()
  {
    if(m_swapChain.Expired())
    {
      WKR_CORE_LOG("Swap Chain Expired");
      return;
    }
    m_swapChain.Lock()->SwapBuffers();
  }
}
