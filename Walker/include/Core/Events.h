#pragma once

#include <Core/Event.h>

using WindowResizeEvent = wkr::TEventDispatcher<uint32_t, uint32_t>;
using WindowSetFullscreenEvent = wkr::TEventDispatcher<uint64_t>;
using ChangeVSyncEvent = wkr::TEventDispatcher<uint16_t>;
