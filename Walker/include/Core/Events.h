#pragma once

#include <Core/Event.h>

using WindowResizeEvent = wkr::EventDispatcher<int, int>;
using WindowSetFullscreenEvent = wkr::EventDispatcher<bool>;
