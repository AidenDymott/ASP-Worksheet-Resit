# Task Three

## Part One - Benchmarking function

To test the bump allocator used for the previous taks I decided to create a simple function that add/removes 1000 items from the bump's memory, then within the main function using elements from the chrono libray took
the start and end time of the function running and used them to see how long it took the function to complete running.

![Test Func](test_bench.png)