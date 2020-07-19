
int maxSeq(int * array, int  n){
if (n == 1 || n == 0)
  return n;
  int length = 1,maxL=1;
  for (int i=0; i < n; i++){
    if (array[i]<array[i+1])
      length++;
    else{
      if (length > maxL)
	maxL = length;
      length =1;
    }
  }
if (length > maxL)
    maxL =length;
return  maxL;
}
