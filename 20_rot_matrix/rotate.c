void rotate(char matrix[10][10]){
  char temp [10][10];
  for (int i=0;i<10;i++)
    for (int j=0;j<10;j++)
      temp[i][j] = matrix[i][j];
  for (int i=0;i<10;i++)
    for (int j=0;j<10;j++)
      matrix[i][j] = temp[10-j-1][i];
}
