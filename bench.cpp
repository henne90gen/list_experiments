#include <benchmark/benchmark.h>

#include "CopyList.h"
#include "IndirectList.h"
#include "LinkedList.h"

constexpr unsigned int RANGE_END = 8 << 10;

static void BM_CopyList(benchmark::State &state) {
  for (auto _ : state) {
    auto list = CopyList<int>();
    for (int i = 0; i < state.range(0); i++) {
      list.add(i);
    }
    benchmark::DoNotOptimize(list.data());
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_CopyList)->Range(8, RANGE_END);

static void BM_CopyListPresized(benchmark::State &state) {
  for (auto _ : state) {
    auto list = CopyList<int>(state.range(0));
    for (int i = 0; i < state.range(0); i++) {
      list.add(i);
    }
    benchmark::DoNotOptimize(list.data());
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_CopyListPresized)->Range(8, RANGE_END);

#define BM_IndirectListFunc(BUCKET_SIZE)                                       \
  static void BM_IndirectList##BUCKET_SIZE(benchmark::State &state) {          \
    for (auto _ : state) {                                                     \
      auto list = IndirectList<int, BUCKET_SIZE>();                            \
      for (int i = 0; i < state.range(0); i++) {                               \
        list.add(i);                                                           \
      }                                                                        \
      benchmark::DoNotOptimize(list.data());                                   \
      benchmark::ClobberMemory();                                              \
    }                                                                          \
  }                                                                            \
  BENCHMARK(BM_IndirectList##BUCKET_SIZE)->Range(8, RANGE_END);
BM_IndirectListFunc(8)
BM_IndirectListFunc(16)
BM_IndirectListFunc(32)
BM_IndirectListFunc(64)
BM_IndirectListFunc(128)
BM_IndirectListFunc(256)

static void BM_LinkedList(benchmark::State &state) {
  for (auto _ : state) {
    auto list = LinkedList<int>();
    for (int i = 0; i < state.range(0); i++) {
      list.add(i);
    }
    benchmark::DoNotOptimize(list);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_LinkedList)->Range(8, RANGE_END);

static void BM_StdVector(benchmark::State &state) {
  for (auto _ : state) {
    auto list = std::vector<int>();
    for (int i = 0; i < state.range(0); i++) {
      list.push_back(i);
    }
    benchmark::DoNotOptimize(list.data());
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_StdVector)->Range(8, RANGE_END);

static void BM_StdVectorPresized(benchmark::State &state) {
  for (auto _ : state) {
    auto list = std::vector<int>(state.range(0));
    for (int i = 0; i < state.range(0); i++) {
      list[i] = i;
    }
    benchmark::DoNotOptimize(list.data());
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_StdVectorPresized)->Range(8, RANGE_END);

BENCHMARK_MAIN();
