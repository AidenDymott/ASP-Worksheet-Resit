#include "heap.hpp"

int main ()
{
  bump myBump;
  myBump.allocate_func(); //runs allocation

  myBump.TEST_MEMORY_SIZE();//should return memory correct size

  myBump.deallocate_func(); //calls pointer clear
  
  return 0;
}