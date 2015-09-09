#include <stdio.h>
#include <stdlib.h>

unsigned int power(unsigned int x, unsigned int y){
  if (y==1){

    return x;
  }
  else if(y<1){
    
    return 0;
  }
  else{
    return x*power(x,y-1);
  }

}

int main(){
  
  unsigned int x =10;
  unsigned int y = 3;
  for (x=0;x<=20;x++){
  unsigned int p = power(x,y);

  printf("power of %d and %d is %d\n",x,y,p);
  }
  return 0;
}
