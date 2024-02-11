#pragma once

#include "Core/PlatformDetection.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>


#if defined(WKR_PLATFORM_WINDOWS)
  #include <windows.h>
#endif

#include <Core/Base.h>
