#include <stdio.h>

int fib(int n){
  if (n<=0){
    return 0;
  }
  if(n==1){
    return 1;
  }
  if(n>=2){
    return fib(n-1)+fib(n-2);
  }
  return 0;
}
int main(){

  for(int i =-2;i<=30;i++){
    int result = fib(i);
    printf("fib(%d)=%d\n",i,result);

  }
}
