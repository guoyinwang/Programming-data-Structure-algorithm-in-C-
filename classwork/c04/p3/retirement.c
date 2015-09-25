#include <stdio.h>
#include <stdlib.h>

typedef struct retir{
  int month;
  double contribute;
  double rate;

}retire_info;
 

void calculate(int* startAge,double* initial,retire_info wr){
  
  for(int i=0;i<wr.month;i++){
    (*startAge)++;
    int year = (*startAge)/12;
    int month = (*startAge)%12;
    (*initial) +=(*initial) * wr.rate + wr.contribute;
    printf("Age %3d month %2d, you have $ %.2lf\n",year,month,*initial);

    
  }
}




 void retirement (int startAge,   //in months
                       double initial, //initial savings in dollars
                       retire_info working, //info about working
                       retire_info retired) //info about being retired
 {
   printf("%d %f\n",*(&startAge),initial);
   calculate(&startAge, &initial,working);
   //calculate(&startAge, &initial,retired);


 }


int main(){
  int startAge = 327;
  double initial = 21345;
  retire_info working;
  retire_info retired;
  working.month = 489;
  working.contribute = 1000;
  working.rate = 0.045/12;
  retired.month = 384;
  retired.contribute = -4000;
  retired.rate = 0.01/12;
  
  retirement(startAge,initial,working,retired);

}
