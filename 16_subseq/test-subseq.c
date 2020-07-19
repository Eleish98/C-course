#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n);

int main(void){
  int a[1] = {0};
  int b[4] = {1,2,5,0};
  int c[18] = {1,2,3,4,3,2,0,3,4,5,6,7,8,3,2,5,6,7};
  int d[3] = {0,0,0};
  if (maxSeq(a,0) !=0)
    printf("aa");
  if (maxSeq(b,4) != 3)
    printf("bb");
  if (maxSeq(c,18) != 7)
    printf("cc");
  if (maxSeq(d,3) != 1)
    printf("dd");
  printf("success\n");
  return EXIT_SUCCESS;
}
