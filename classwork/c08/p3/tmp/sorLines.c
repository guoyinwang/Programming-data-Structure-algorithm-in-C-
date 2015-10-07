#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
void printData(char ** data, size_t count){
  for(size_t i=0;i<count;i++){
    printf("%s", data[i]);
  }
}
char **  getData(FILE *f, char ** data){
  char * line =NULL;
  size_t sz;
  size_t size=0 * sizeof(*data);
  
  while((getline(&line,&sz,f))>0){
    size++;
    data = realloc(data,size*sizeof(*data));
    // data[size-1] = realloc(data[size-1],strlen(line)*sizeof(**data));
    data[size-1] = line;
    line =NULL;
  }
  //  free(line);
  printData(data,size);
  return data;
}


void freedata(char ** data, size_t count){
  for(size_t i=0;i<count;i++){
    free(data[i]);
    
  }
  free(data);
}


int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!


  if (argc ==1){
     char * fileName = "input.txt";
     FILE *f = fopen(fileName,"r");
     char ** data = NULL;
     data = getData(f,data);
      
     //sortData(data,size);
     // printData(data,size);
     fclose(f);
     free(fileName);
  }
  else{
    for (int i =0;i<argc;i++){
      char * fileName = argv[i+1];
      FILE *f = fopen(fileName,"r");
      char ** data =NULL;
      data = getData(f,data);
      
      // sortData(data,size);
      //    print(data,size);
      fclose(f);
      free(fileName);
   }

  }
 
  return EXIT_SUCCESS;
}
