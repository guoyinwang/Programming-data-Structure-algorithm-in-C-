#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * newCount = malloc(sizeof(*newCount));
  newCount->countArray = NULL;
  newCount->sizeofArray = 0;
  newCount->unknownNum = 0;
  
  return newCount;
  
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name==NULL){
    c->unknownNum ++;
  }
  else{
    int find =0;
    for(int i=0;i<c->sizeofArray;i++){
      if(strncmp((c->countArray[i].stringName),name,strlen(name))==0){
	c->countArray[i].oneCount++;
	find =1;
	break;
      }
    }
    if(find==0){
      c->sizeofArray++;
      c->countArray = realloc(c->countArray,c->sizeofArray*sizeof(*(c->countArray)));
      
      c->countArray[c->sizeofArray-1].stringName= malloc((strlen(name)+1)*sizeof(* c->countArray[c->sizeofArray-1].stringName));
      c->countArray[c->sizeofArray-1].stringName = strncpy(c->countArray[c->sizeofArray-1].stringName,name,strlen(name)+1);
      c->countArray[c->sizeofArray-1].oneCount =1;
    }
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i=0; i < c->sizeofArray;i++){
    fprintf(outFile,"%s:%d\n",c->countArray[i].stringName, c->countArray[i].oneCount);
  }
  fprintf(outFile,"<unknown>:%d\n", c->unknownNum);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int i=0;i< c->sizeofArray;i++){
    free(c->countArray[i].stringName);
  }
  free(c->countArray);
  free(c);
}
