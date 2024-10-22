#pragma once

#include "OS/IOSAbstractFactory.h"

namespace wkr::os {

class UOSFactory {
 public:
  static void Init();
  static inline IOSAbstractFactory& Get() { return s_instance.Get(); }
  static inline void Destroy() { s_instance.Release(); }

 private:
  static inline mem::TScope<IOSAbstractFactory> s_instance;
};

}  // namespace wkr::os
