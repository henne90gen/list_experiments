#pragma once

template <typename T, size_t BUCKET_SIZE = 128> class IndirectList {
public:
  IndirectList() {
    buckets = (T **)std::malloc(sizeof(T *) * bucketsCount);
    buckets[currentBucket] = (T *)std::malloc(sizeof(T) * BUCKET_SIZE);
  }
  ~IndirectList() {
    for (size_t i = 0; i < currentBucket; i++) {
      std::free(buckets[i]);
    }
    std::free(buckets);
  }

  unsigned int size() {
    return currentBucket * BUCKET_SIZE + currentBucketSize;
  }

  void add(T value) {
    if (currentBucketSize >= BUCKET_SIZE) {
      createBucket();
    }
    buckets[currentBucket][currentBucketSize] = value;
    currentBucketSize++;
  }

  T operator[](size_t index) const {
    return buckets[index / BUCKET_SIZE][index % BUCKET_SIZE];
  }

  T &operator[](size_t index) {
    size_t bucketIndex = index / BUCKET_SIZE;
    size_t innerIndex = index % BUCKET_SIZE;
    return buckets[bucketIndex][innerIndex];
  }

  T **data() { return buckets; }

private:
  void createBucket() {
    if (currentBucket + 1 >= bucketsCount) {
      size_t newBucketsCount = bucketsCount * 2;
      T **newBuckets = (T **)std::malloc(sizeof(T *) * newBucketsCount);
      std::memcpy(newBuckets, buckets, sizeof(T *) * (currentBucket + 1));
      std::free(buckets);
      buckets = newBuckets;
      bucketsCount = newBucketsCount;
    }
    currentBucket++;
    buckets[currentBucket] = (T *)std::malloc(sizeof(T) * BUCKET_SIZE);
    currentBucketSize = 0;
  }

  T **buckets;
  size_t bucketsCount = 64;
  size_t currentBucket = 0;
  size_t currentBucketSize = 0;
};
