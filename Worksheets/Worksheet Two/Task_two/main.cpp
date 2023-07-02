#include "bump.hpp"
#include "simpletest.h"

#define RUN_TEST(testFunc) \
    do { \
        std::cout << "Running test: " << #testFunc << std::endl; \
        try { \
            testFunc(); \
            std::cout << "Test passed" << std::endl; \
        } catch (const std::exception& ex) { \
            std::cout << "Test failed: " << ex.what() << std::endl; \
        } \
        std::cout << std::endl; \
    } while (false)

#define ASSERT_TRUE(condition, message) \
    do { \
        if (!(condition)) { \
            throw std::runtime_error(message); \
        } \
    } while (false)

//Test case 1: Allocate and deallocate an int.
void testBumpAllocator1() {
    //Obj of bumpallocator.
    BumpAllocator<int, 1024> allocator;
    //Allocate int + assign mem add to ptr.
    int* ptr = allocator.alloc<int>();
    //Check ptr value.
    ASSERT_TRUE(ptr != nullptr, "Allocation should not be null");
    //Remove int from mem.
    allocator.dealloc(ptr);
}

//Test case 2: Allocate more elements than available memory.
void testBumpAllocator2() {
    BumpAllocator<int, 16> allocator;
    //Allocate int + assign mem add to ptr.
    int* ptr = allocator.alloc<int>(10);
    //Check ptr value.
    ASSERT_TRUE(ptr == nullptr, "Allocation should be null");
}

//Test case 3: Allocate and deallocate multiple elements.
void testBumpAllocator3() {
    BumpAllocator<int, 1024> allocator;
    //Allocate int + assign mem add to ptr.
    int* ptr1 = allocator.alloc<int>();
    int* ptr2 = allocator.alloc<int>();
    //Check ptr value.
    ASSERT_TRUE(ptr1 != nullptr, "Allocation 1 should not be null");
    ASSERT_TRUE(ptr2 != nullptr, "Allocation 2 should not be null");
    //Remove int from mem.
    allocator.dealloc(ptr1);
    allocator.dealloc(ptr2);
}

int main() {
    //Run the tests.
    RUN_TEST(testBumpAllocator1);
    RUN_TEST(testBumpAllocator2);
    RUN_TEST(testBumpAllocator3);

    return 0;
}





