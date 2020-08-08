#include <benchmark/benchmark.h>

#include "CopyList.h"
#include "IndirectList.h"
#include "LinkedList.h"

constexpr unsigned int RANGE_END = 8<<10;

static void BM_CopyList(benchmark::State& state) {
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

static void BM_IndirectList(benchmark::State& state) {
  for (auto _ : state) {
    auto list = IndirectList<int>();
    for (int i = 0; i < state.range(0); i++) {
      list.add(i);
    }
    benchmark::DoNotOptimize(list.data());
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_IndirectList)->Range(8, RANGE_END);

static void BM_LinkedList(benchmark::State& state) {
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

static void BM_StdVector(benchmark::State& state) {
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

BENCHMARK_MAIN();
