#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  
    
  return NULL;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t *kv = readKVs(argv[1]);
  // printKVs(kv);
 //count from 2 to argc (call the number you count i)
  for (int i =2;i<argc;i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    FILE * fin =fopen(argv[i],"r");
    if(fin==NULL){
      perror("cannot read file of argv[i]");
      return EXIT_FAILURE;
    }
    counts_t * c = createCounts();
    size_t  sz =0;
    ssize_t len =0;
    char * line = NULL;
    while((len=getline(&line,&sz,fin))>=0){
      char * lincpy = malloc((strlen(line)-1)*sizeof(*lincpy));
      for(int j=0;j<strlen(line)-1;j++){
	lincpy[j]=line[j];
      }
      char * valueResult = lookupValue(kv,lincpy);
      printf("line is %s\n",lincpy);
      printf("valueResult is %s\n",valueResult);
      addCount(c,valueResult);
    }
    
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);
    
    //open the file named by outName (call that f)
    FILE * f = fopen(outName,"w");
    if(f==NULL){
      perror("open output file is wrong");
      return EXIT_FAILURE;
    }
    //print the counts from c into the FILE f
    printCounts(c,f);
    //close f
    if(fclose(f)<0){
      perror("close f failure.");
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }

 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
