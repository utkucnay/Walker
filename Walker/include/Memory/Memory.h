#pragma once

#include "Memory/Core/IAllocator.h"
#include "Memory/Core/UMemoryPool.h"

#include "Memory/Buffer/CircularBuffer.h"

#include "Memory/Allocator/ArenaAllocater.h"
#include "Memory/Allocator/BuddyAllocater.h"
#include "Memory/Allocator/StackAllocater.h"
#include "Memory/Allocator/TLSFAllocater.h"
#include "Memory/Allocator/USlabAllocater.h"

void* operator new(size_t size) {
  WKR_CORE_LOG("New operator overloading ");
  void* p = malloc(size);
  return p;
}

void operator delete(void* p) {
  WKR_CORE_LOG("Delete operator overloading ");
  free(p);
}
