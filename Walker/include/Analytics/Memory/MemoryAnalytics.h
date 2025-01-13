#pragma once

namespace wkr::analytics {

class MemoryAnalytics {
 public:
  static void CreateInstance() { s_instance = new MemoryAnalytics(); }

  static MemoryAnalytics& GetInstance() { return *s_instance; }

  static b32 HasInstance() { return s_instance != nullptr; }

  static void DestroyInstance() {
    delete s_instance;
    s_instance = nullptr;
  }

 public:
  void StartTracking() { m_isStartAnaltytics = true; }

  std::string StopTracking() {
    m_isStartAnaltytics = false;

    std::stringstream ss;
    ss << "Allocated Objects Count : " << m_allocatedObjectsCount << "\n";
    for (size_t i = 0; i < m_allocatedObjectsCount; ++i) {
      ss << i + 1 << ". Allocated Object Size: " << m_allocatedObjectsSizes[i]
         << "\n";
    }
    ss << "Deallocated Objects Count : " << m_deallocatedObjectsCount << "\n";

    Clear();
    return ss.str();
  }

  void AddAlloctedObject(u64 size) {
    if (!m_isStartAnaltytics)
      return;
    m_allocatedObjectsSizes[m_allocatedObjectsCount++] = size;
  }

  void AddDealloctedObject() {
    if (!m_isStartAnaltytics)
      return;
    ++m_deallocatedObjectsCount;
  }

  void Clear() {
    m_allocatedObjectsCount = 0;
    //m_allocatedObjectsSizes;

    m_deallocatedObjectsCount = 0;
  }

 private:
  u64 m_allocatedObjectsCount;
  std::array<u64, 100000> m_allocatedObjectsSizes;

  u64 m_deallocatedObjectsCount;

  b32 m_isStartAnaltytics;

  static inline MemoryAnalytics* s_instance;
};

}  // namespace wkr::analytics
