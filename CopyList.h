#pragma once

#include <cstring>
template <typename T> class CopyList {
public:
  CopyList() { data = (T *)std::malloc(sizeof(T) * maxSize); }

  unsigned int size() { return currentSize; }

  void add(T value) {
    if (currentSize >= maxSize) {
      resize(maxSize * 2);
    }
    data[currentSize++] = value;
  }

  T operator[](size_t index) const { return data[index]; }
  T &operator[](size_t index) { return data[index]; }

private:
  void resize(size_t newSize) {
    T *newData = (T *)std::malloc(sizeof(T) * newSize);
    std::memcpy(newData, data, sizeof(T) * currentSize);
    data = newData;
    maxSize = newSize;
  }

  T *data;
  size_t currentSize = 0;
  size_t maxSize = 32;
};
