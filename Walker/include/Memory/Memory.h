#pragma once

#include "Analytics/Memory/MemoryAnalytics.h"
#include "Memory/Core/IAllocator.h"
#include "Memory/Core/UMemoryPool.h"

#include "Memory/Buffer/CircularBuffer.h"

#include "Memory/Allocator/ArenaAllocater.h"
#include "Memory/Allocator/BuddyAllocater.h"
#include "Memory/Allocator/StackAllocater.h"
#include "Memory/Allocator/TLSFAllocater.h"
#include "Memory/Allocator/USlabAllocater.h"

void* operator new(size_t size) {
  if(wkr::analytics::MemoryAnalytics::HasInstance())
    wkr::analytics::MemoryAnalytics::GetInstance().AddAlloctedObject(size);

  void* p = malloc(size);
  return p;
}

void operator delete(void* p) {
  if(wkr::analytics::MemoryAnalytics::HasInstance())
    wkr::analytics::MemoryAnalytics::GetInstance().AddDealloctedObject();
  free(p);
}
