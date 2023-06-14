#include "heap.hpp"

int main ()
{
  bump myBump;//obj creation

  myBump.allocate_func(); //runs allocation
  myBump.deallocate_func(); //calls pointer clear

  return 0;
}