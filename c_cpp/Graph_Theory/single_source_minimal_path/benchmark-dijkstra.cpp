#include <benchmark/benchmark.h>
#include <thread>
using namespace std::chrono_literals;

static void BM_SomeFunction(benchmark::State& state) {
    // Perform setup here
    for (auto _ : state) {
        // This code gets timed
        std::this_thread::sleep_for(1s);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();
