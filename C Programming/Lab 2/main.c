#include "stdio.h"
#include "stdlib.h"
#include "count.h"
#include "readFile.h"

#define FILE_NOT_EXIST -1
#define ALLOC_ERROR -2

int main(int argc, char const *argv[]) {
  int NumberOfElements;
  FILE *inputFile;
  if (argc != 2){
    printf("Wrong number of arguments\n");
    return 0;
  }
  inputFile = fopen(argv[1], "r");
  if (inputFile == NULL){
    fprintf(stderr, "File doesn't exist\n");
    return FILE_NOT_EXIST;
  }
  if (read_from_file(&NumberOfElements, inputFile) == BADEL){
    return 0;
  }
  int *memory = NULL;
  memory = malloc(NumberOfElements * sizeof(int));

  if (memory == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return ALLOC_ERROR;
  }

  int *memBegin = memory;
  int *memEnd = memory + NumberOfElements;
  rewind(inputFile);
  int res = read_to_mem(memBegin, memEnd, inputFile);
  if (res != 0){
    free(memory);
    fclose(inputFile);
    return 0;
  }
  memBegin = memory;
  int uniqueElementsCounter = countExistance(memBegin, memEnd);
  printf("uniqueElementsCounter = %d \n",uniqueElementsCounter );
  fclose(inputFile);
  free(memory);
  return 0;
}
