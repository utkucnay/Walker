#pragma once

#include <Core/Event.h>

using WindowResizeEvent = wkr::EventDispatcher<int, int>;
using WindowSetFullscreenEvent = wkr::EventDispatcher<bool>;
using ChangeVSyncEvent = wkr::EventDispatcher<uint16_t>;
