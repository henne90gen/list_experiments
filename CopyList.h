#pragma once

#include <cstring>
template <typename T> class CopyList {
public:
  CopyList() { memory = (T *)std::malloc(sizeof(T) * maxSize); }
  CopyList(size_t maxSize) : maxSize(maxSize) {
    memory = (T *)std::malloc(sizeof(T) * maxSize);
  }
  ~CopyList() { std::free(memory); }

  unsigned int size() { return currentSize; }

  void add(T value) {
    if (currentSize >= maxSize) {
      resize(maxSize * 2);
    }
    memory[currentSize++] = value;
  }

  T operator[](size_t index) const { return memory[index]; }
  T &operator[](size_t index) { return memory[index]; }

  T *data() { return memory; }

private:
  void resize(size_t newSize) {
    T *newData = (T *)std::malloc(sizeof(T) * newSize);
    std::memcpy(newData, memory, sizeof(T) * currentSize);
    std::free(memory);
    memory = newData;
    maxSize = newSize;
  }

  T *memory;
  size_t currentSize = 0;
  size_t maxSize = 32;
};
