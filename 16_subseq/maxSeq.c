
int maxSeq(int * array, size_t n){
  double length = 0,maxL=0;
  for (int i=0; i < n; i++){
    if (array[i]<array[i+1])
      length++;
    else{
      if (length > maxL)
	maxL = length;
      length =0;
    }
  }
  if (length > maxL)
    maxL =length;
return (int) maxL;
}
