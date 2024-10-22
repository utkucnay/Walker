#include "Core/AWindow.h"

namespace wkr {

void AWindow::SwapBuffers() {
  if (m_swapChain.Expired()) {
    WKR_CORE_LOG("Swap Chain Expired");
    return;
  }
  m_swapChain.Lock()->SwapBuffers();
}

}  // namespace wkr
