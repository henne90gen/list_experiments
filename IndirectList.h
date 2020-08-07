#pragma once

constexpr size_t bucketSize = 64;

template <typename T> class IndirectList {
public:
  IndirectList() {
    buckets = (T **)std::malloc(sizeof(T *) * bucketsMaxSize);
    buckets[currentBucket] = (T *)std::malloc(sizeof(T) * bucketSize);
  }

  unsigned int size() { return currentBucket * bucketSize + currentBucketSize; }

  void add(T value) {
    if (currentBucketSize >= bucketSize) {
      createBucket();
    }
    buckets[currentBucket][currentBucketSize++] = value;
  }

  T operator[](size_t index) const {
    return buckets[index / bucketSize][index % bucketSize];
  }

  T &operator[](size_t index) {
    return buckets[index / bucketSize][index % bucketSize];
  }

private:
  void createBucket() {
    if (currentBucket + 1 >= bucketsMaxSize) {
      size_t newBucketsMaxSize = bucketsMaxSize * 2;
      T **newBuckets = (T **)std::malloc(sizeof(T *) * newBucketsMaxSize);
      std::memcpy(newBuckets, buckets, sizeof(T *) * currentBucket);
      buckets = newBuckets;
      bucketsMaxSize = newBucketsMaxSize;
    }
    currentBucket++;
    buckets[currentBucket] = (T *)std::malloc(sizeof(T) * bucketSize);
    currentBucketSize = 0;
  }

  T **buckets;
  size_t bucketsMaxSize = 64;
  size_t currentBucket = 0;
  size_t currentBucketSize = 0;
};
