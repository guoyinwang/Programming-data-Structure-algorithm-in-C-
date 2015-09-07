#include <stdio.h>
#include <stdlib.h>


void printFactors(int n) {
  if (n<=1){
    printf("\n");
    return;
  }
  else if(n==2){
    printf("2\n");
    return;
  }
  else if (n==3){
    printf("3\n");
    return;
  }
  else{
    int i =2;
    int t = 1;
    while(t){
      if (i==n){
	printf("%d\n",i);
	t=0;
      }
      else if(n%i==0){
	printf("%d*",i);
	printFactors(n/i);
	t=0;
      }
      i++;
      
    }
    return;
  }
}

int main(void) {
  printf("Factorization of 1:\n");
  printFactors(1);
  printf("Factorization of 60:\n");
  printFactors(60);
  printf("Factorization of 132:\n");
  printFactors(132);
  printf("Factorization of 11726:\n");
  printFactors(11726);
  printf("Factorization of 2169720:\n");
  printFactors(2169720);
  printf("Factorization of 1789220887:\n");
  printFactors(1789220887);
  return EXIT_SUCCESS;
}
