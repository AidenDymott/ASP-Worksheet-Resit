#include "benchmark.hpp"

int main() {

    BenchmarkSuite suite;
    suite.registerBenchmark("Small Allocations", benchmarkSmallAllocations);
    suite.registerBenchmark("Large Allocations", benchmarkLargeAllocations);

    suite.runAll();

    return 0;

}





