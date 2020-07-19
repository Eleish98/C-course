
size_t maxSeq(int * array, size_t  n){
  if (n == 1 || n == 0)
    return n;
  if (n<0)
    return 0;
  int length = 1, maxL=1;
  for (int i=0; i < n; i++){
    if (array[i]<array[i+1])
      length+=1;
    else{
      if (length > maxL)
	maxL = length;
      length =0;
    }
  }
  if (length > maxL)
    maxL =length;
  return  maxL;
}
