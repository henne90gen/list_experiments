cmake_minimum_required(VERSION 3.16)

project(ListExperiments)

add_executable(Main main.cpp)

find_package(benchmark REQUIRED)
add_executable(Benchmarks bench.cpp)
target_link_libraries(Benchmarks benchmark::benchmark)
