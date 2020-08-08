# List Experiments

Three different implementations of a dynamic list.

## Benchmark Results

| Benchmark            | Time      | CPU       | Iterations |
| -------------------- | --------- | --------- | ---------- |
| BM_CopyList/8        |   23.0 ns |   22.9 ns |   28738533 |
| BM_CopyList/64       |   77.7 ns |   77.5 ns |    8520024 |
| BM_CopyList/512      |    600 ns |    598 ns |    1185862 |
| BM_CopyList/4096     |   2469 ns |   2462 ns |     292242 |
| BM_CopyList/8192     |   4293 ns |   4289 ns |     147627 |
| BM_IndirectList/8    |    127 ns |    127 ns |    5350101 |
| BM_IndirectList/64   |    165 ns |    165 ns |    4148153 |
| BM_IndirectList/512  |    555 ns |    555 ns |    1333858 |
| BM_IndirectList/4096 |   4684 ns |   4678 ns |     149769 |
| BM_IndirectList/8192 |   9796 ns |   9782 ns |      70796 |
| BM_LinkedList/8      |    122 ns |    122 ns |    5899107 |
| BM_LinkedList/64     |   1048 ns |   1047 ns |     672921 |
| BM_LinkedList/512    |   8458 ns |   8450 ns |      81409 |
| BM_LinkedList/4096   |  72754 ns |  72646 ns |       9992 |
| BM_LinkedList/8192   | 141797 ns | 141633 ns |       4593 |
| BM_StdVector/8       |   67.8 ns |   67.7 ns |   10586123 |
| BM_StdVector/64      |    155 ns |    154 ns |    4577282 |
| BM_StdVector/512     |    555 ns |    554 ns |    1280507 |
| BM_StdVector/4096    |   3199 ns |   3196 ns |     215537 |
| BM_StdVector/8192    |   6407 ns |   6399 ns |     111748 |
