#include <stdlib.h>
size_t maxSeq(int * array, size_t  n){
  if (n == 1 || n == 0)
    return n;
  if (n<0)
    return 0;
  size_t length = 1, maxL=1;
  for (long i=1; i <n; i++){
    if (array[i-1]<array[i])
      length+=1;
    else{
      if (length > maxL)
	maxL = length;
      length =1;
    }
  }
  if (length >= maxL)
    maxL =length;
  return  maxL;
}
