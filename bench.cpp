#include <benchmark/benchmark.h>

#include "CopyList.h"
#include "IndirectList.h"

static void BM_CopyList(benchmark::State& state) {
  auto list = CopyList<int>();
  for (auto _ : state) {
    for (int i = 0; i < state.range(0); i++) {
      list.add(i);
    }
    benchmark::DoNotOptimize(list);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_CopyList)->Range(8, 8<<10);

static void BM_IndirectList(benchmark::State& state) {
  auto list = IndirectList<int>();
  for (auto _ : state) {
    for (int i = 0; i < state.range(0); i++) {
      list.add(i);
    }
    benchmark::DoNotOptimize(list);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_IndirectList)->Range(8, 8<<10);

BENCHMARK_MAIN();
