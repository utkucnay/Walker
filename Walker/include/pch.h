#pragma once

#include <Core/PlatformDetection.h>

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <Core/Base.h>
#include <Core/Event.h>
#include <Core/Events.h>

#include <Memory/Ref.h>
#include <Memory/WeakRef.h>
#include <Memory/Scope.h>

#include <Core/Builder.h>
#include <Core/Factory.h>

#include <Core/Events.h>

#if defined(WKR_PLATFORM_WINDOWS)
  #include <windows.h>
#endif

#include <Render/RenderPCH.h>
