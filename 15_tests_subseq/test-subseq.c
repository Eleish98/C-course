#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n);

int main(void){
  int a[] = {};
  int b[4] = {1,2,5,0};
  int c[5] = {-1,-1,0,1,3};
  int d[3] = {0,0,0};
  if (maxSeq(a,0) !=0)
    return EXIT_FAILURE;
  if (maxSeq(b,4) != 3)
    return EXIT_FAILURE;
  if (maxSeq(c,5) != 4)
    return EXIT_FAILURE;
  if (maxSeq(d,3) != 1)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
