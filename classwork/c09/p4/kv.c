#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  kvarray_t * kvarray=malloc(sizeof(*kvarray));
  kvarray->pairs =NULL;
  kvarray->length = 0; 
  FILE *f = fopen(fname,"r");
  if(f==NULL){
    perror("open file failed\n");
    return NULL;
  }
  char * line=NULL;
  size_t sz;
  while((getline(&line,&sz,f)>=0)){
    char * lincpy = malloc((strlen(line)-1)*sizeof(*lincpy));
    for(int j=0;j<strlen(line)-1;j++){
      lincpy[j]=line[j];
    }
      char * pch =strtok(lincpy,"=");
      char * key = pch;
      pch =NULL;
      pch = strtok(NULL,"=");
      char * value = pch;
      (kvarray->length)++;
      kvarray->pairs = realloc(kvarray->pairs,(kvarray->length)*sizeof(*(kvarray->pairs)));
      kvarray->pairs[(kvarray->length)-1].key = key;
      kvarray->pairs[(kvarray->length)-1].value = value;
      key =NULL;
      value = NULL;
      line = NULL;
      free(key);
      free(value);
      //free(lincpy);
  }
  free(line);
  
  if(fclose(f)<0){
    perror("close file failed\n");
    return NULL;
  }
    
  return kvarray;  
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  
  for(int i=0;i<pairs->length;i++){
    
    free(pairs->pairs[i].key);
    // free(pairs->pairs[i].value);
  }
  
  free(pairs->pairs);
  
  free(pairs);
  
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i<pairs->length;i++){
    printf("keys is %s, value is %s\n",pairs->pairs[i].key,pairs->pairs[i].value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(int i=0; i< pairs->length;i++){
    if (strncmp(pairs->pairs[i].key,key,strlen(pairs->pairs[i].key))==0){
	return pairs->pairs[i].value;
      }

  }

  return NULL;
}
