#include <stdlib.h>
#include <stdio.h>

 struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
 };
typedef struct  _retire_info retire_info;

double disp(retire_info, int, double); 
void retirement(int startAge, double initial, retire_info working, retire_info retired){
 initial =  disp(working, startAge, initial);
 initial =  disp(retired, startAge+working.months, initial);
}

double  disp(retire_info X,int startAge, double initial){
  for (int i = 0; i < X.months ; i++){
    printf("Age %3d month %2d you have $%.2f\n", (startAge+i)/12, (startAge+i)%12,initial);
    initial += initial * X.rate_of_return + X.contribution;
  }
  return initial;
}

int main (void){
  retire_info working, retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/(float)12;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/(float)12;

  retirement(327,21345,working,retired);

  return 0;
}
