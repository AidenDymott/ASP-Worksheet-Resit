#include "bump.hpp"

#include <chrono>
#include <iostream>

//Bump func to run
void benchmarkSmallAllocations()
{
    //obj of bump
    BumpAllocator<int, 1024> allocator;
    //Loop that adds and deallocates int's to the bump mem.
    for (int i = 0; i < 1000; ++i)
    {
        int* ptr = allocator.alloc<int>();
        allocator.dealloc(ptr);
    }
}

int main() {
        //Takes the start time of a func and stores it.
        auto start = std::chrono::high_resolution_clock::now();
        benchmarkSmallAllocations();
        //Takes end time of the func and stores it.
        auto end = std::chrono::high_resolution_clock::now();
        //Calc the duration of func run time.
        std::chrono::duration<double, std::milli> duration = end - start;
        //Output run time of func.
        std::cout << "Execution time: " << duration.count() << "ms\n";

    return 0;
}





