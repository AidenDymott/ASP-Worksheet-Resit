#include <chrono>
#include <vector>
#include <string>
#include <functional>

#include "bump.hpp"

//Benchmarking function.
template <typename Function>
void benchmark(Function func)
{
    //Takes function start time.
    auto start = std::chrono::high_resolution_clock::now();
    //Runs fed function.
    func();
    //Takes function end time.
    auto end = std::chrono::high_resolution_clock::now();
    //Calcs run time.
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Execution time: " << duration.count() << "ms\n";
}

//Benchmark suite implementation

class BenchmarkSuite
{
public:
//Create a function template that takes the name and function and stores them as a name/func pair.
    template <typename Function>
    void registerBenchmark(const std::string& name, Function func)
    {
        benchmarks.emplace_back(name, func);
    }
//Create a func that runs through each stored benchmarks and then executes each of them(For this two different functions).
    void runAll()
    {
        for (const auto& benchmark : benchmarks)
        {
            std::cout << "Running benchmark: " << benchmark.first << std::endl; //Prints name of function.
            benchmark.second(); //Executes actual function.
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::pair<std::string, std::function<void()>>> benchmarks; //Uses a vector to store benchmarks as a pair(name, function).
};

//Adds and removes 1000 ints one by one into mem.
void benchmarkSmallAllocations()
{
    BumpAllocator<int, 1024> allocator;
    for (int i = 0; i < 1000; ++i)
    {
        int* ptr = allocator.alloc<int>();
        allocator.dealloc(ptr);
    }
}

//Adds and removes 100 int values at a time, repeats 10 times.
void benchmarkLargeAllocations()
{
    BumpAllocator<int, 1024> allocator;
    for (int i = 0; i < 10; ++i)
    {
        int* ptr = allocator.alloc<int>(100);
        allocator.dealloc(ptr);
    }
}
