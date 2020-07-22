#include <stdlib.h>
#include <stdio.h>

unsigned power(unsigned, unsigned);

int main(void){
  if (power(1,0) != 1)
    return EXIT_FAILURE;
  if (power(-1,0) != 1)
    return EXIT_FAILURE;
  if (power(0,10) != 0)
    return EXIT_FAILURE;
  if (power(1,19) != 1)
    return EXIT_FAILURE;
  if (power(154,1) != 154)
    return EXIT_FAILURE;
  if (power(-2,2) != 4)
    return EXIT_FAILURE;
  if (power(-2,5) != -32)
    return EXIT_FAILURE;
  if (power(0,0) != 1)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
