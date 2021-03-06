#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int maxIndex(int * p, int len){
  int max =0;
  int index =0;
  for (int i=0;i<len;i++){
    if(max<p[i]){
      max = p[i];
      index =i;
    }

  }
  return index;

}
int frequencyCheck(FILE * f){
  int freq[26]={0};
  int c ;
  while(( c = fgetc(f)) !=EOF){
    if (isalpha(c)){
      freq[c-'a']++;
    }

  }
  int key  = maxIndex(freq,26);
  return key;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: break inputFileName\n");
    return EXIT_FAILURE;
  }
 
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int key = frequencyCheck(f);
  fprintf(stdout,"%d\n",key);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
