#include "stdio.h"
#include "stdlib.h"
#include "count.h"
#include "readFile.h"

#define FILE_NOT_EXIST -1
#define ALLOC_ERROR -2

int main() {
  int NumberOfElements;
  FILE *inputFile;
  inputFile = fopen("input.txt", "r");
  if (inputFile == NULL){
    fprintf(stderr, "File doesn't exist\n");
    return FILE_NOT_EXIST;
  }
  read_from_file(&NumberOfElements, inputFile);
  int *memory = NULL;
  memory = malloc(NumberOfElements * sizeof(int));

  if (memory == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return ALLOC_ERROR;
  }

  int *memBegin = memory;
  int *memEnd = memory + NumberOfElements;
  rewind(inputFile);
  while (memBegin != memEnd) {
    fscanf(inputFile, "%d", memBegin);
    memBegin++;
  }
  memBegin = memory;
  int uniqueElementsCounter = countExistance(memBegin, memEnd);
  printf("uniqueElementsCounter = %d\n",uniqueElementsCounter );
  return 0;
}
