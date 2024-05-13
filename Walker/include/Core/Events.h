#pragma once

#include <Core/Event.h>

using WindowResizeEvent = wkr::EventDispatcher<uint32_t, uint32_t>;
using WindowSetFullscreenEvent = wkr::EventDispatcher<uint64_t>;
using ChangeVSyncEvent = wkr::EventDispatcher<uint16_t>;
