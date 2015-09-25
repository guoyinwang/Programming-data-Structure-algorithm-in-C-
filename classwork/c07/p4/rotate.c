#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>





int main(int argc, char** argv){
  if(argc != 2){
    fprintf(stderr,"inputfile\n");
    return EXIT_FAILURE;

  }
  FILE * f = fopen(argv[1],"r");
  char matrix[10][10];
  for(int i=0;i<10;i++){
    fgets(matrix[i],11,f);
    fgetc(f);


  }


  // print matrix for test
  for(int i=0;i<10;i++){
    for(int j =0;j<10;j++){
      printf("%c",matrix[i][j]);
    }
    printf("\n");
  }

  char matrixtmp[10][10];
  for(int i=0;i<10;i++){
    for(int j =0;j<10;j++){
      matrixtmp[j][9-i]=matrix[i][j];
    }
  }
 // print matrix for test
  for(int i=0;i<10;i++){
    for(int j =0;j<10;j++){
      fprintf(stdout,"%c",matrixtmp[i][j]);
    }
    fprintf(stdout,"\n");
  }


  return EXIT_SUCCESS;
}
