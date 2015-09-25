#include <stdio.h>
#include <stdlib.h>

int maxSeq(int * array, int n) {
  if (n==0){
    return 0;
  }
  for(int len = n;len>=1;len--){
    for(int step =0;step<=n-1;step++){
      int label = 1;
      for (int loop=0;loop<=len-2;loop++){
	if(array[step+loop]>=array[step +loop+1]){
	  label=-1;
	}
      }
      if (label == 1){
	return len;
      }
    }
  }

  return 0;
}

void doTest(int * array, int n) {
  printf("maxSeq(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (int i =0; i < n; i++) {
      printf("%d", array[i]);
      if (i < n -1) {
	printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  int ans = maxSeq (array, n);
  printf("%d\n", ans);
}

int main(void) {
  int array1[] = { 1, 2, 3, 2, 4, 6, 9, 11, 13, 13, 15, 1, 2, 3, 2, 1};
  int array2[] = { -100, -99, -98, -97, -96, -95, -94};
  int array3[] = { 1, 1, 2, 3, 5, 8, 13, 8, 5, 4, 1, 2, 3,9};
  int array4[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};

  doTest (array1, 16);
  doTest (array2, 7);
  doTest (array3, 14);
  doTest (array4, 9);
  doTest (NULL, 0);
  doTest (array1, 0);
  
  return EXIT_SUCCESS;
}
