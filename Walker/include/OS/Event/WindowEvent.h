#pragma once

#include "Core/Event.h"

using WindowResizeEvent = wkr::TEventDispatcher<u32, u32>;
using WindowSetFullscreenEvent = wkr::TEventDispatcher<u64>;
