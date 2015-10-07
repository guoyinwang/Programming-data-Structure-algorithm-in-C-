#include<stdio.h>
#include<stdlib.h>



int main(int argc, char** argv){
  if(argc !=3){
    printf("Wrong number of args\n");
    return EXIT_FAILURE;

  }
  FILE * srcfile = fopen(argv[1],"r");
  if (srcfile == NULL){
    perror("ERROR\n");
    return EXIT_FAILURE;

  }

  FILE * desfile = fopen(argv[1],"w");
  if (desfile == NULL){
    perror("ERROR\n");
    return EXIT_FAILURE;

  }
  int c;
  while((c=fgetc(srcfile))!=EOF){
    fprintf(desfile,"%c",c);
  }
  if(fclose(srcfile)!=0){perror("CLOSURE SRCFILE");}
  if(fclose(destfile)!=0){perror("CLOSURE DESTFILE");}
  
  return EXIT_SUCCESS;
}
