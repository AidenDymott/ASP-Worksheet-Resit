#include <iostream>

//Create a template class of the bump allocator.
template <typename T, size_t Size>
class BumpAllocator {
private:
    char heap[Size]; //Sets the heaps memory.
    char* next; //Selects the next available memory address.
    size_t allocationCount; //Counts number of allocations made.

public:
    //Inistiallises the BumbAllocator, sets the ptr next to start of heap, sets alloccationCount to 0.
    BumpAllocator() : next(heap), allocationCount(0) {}
    //Template func for allocation func.
    template <typename U>
    U* alloc(size_t count = 1) {
        //Check to see if theres space to allocate in the heap, uses the next ptr value + size of U and then multiplys by the cuttent count(default 1), to see if there's space
        if (reinterpret_cast<char*>(next) + sizeof(U) * count <= heap + Size) {
            //Create a result pointer
            U* result = reinterpret_cast<U*>(next);
            next += sizeof(U) * count;
            allocationCount++;
            return result;
        }
        return nullptr;
    }
    //Template func for deallocation func.
    template <typename U>

    void dealloc(U* ptr) {
        //Checks that the current heap ptr is valid.
        if (ptr >= reinterpret_cast<U*>(heap) && ptr < reinterpret_cast<U*>(heap + Size)) {
            allocationCount--;
            //If the heap is empty(allocations = 0), reset the ptr to point to the start of the heap.
            if (allocationCount == 0) {
                next = heap;
            }
        }
    }
};
