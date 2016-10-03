#include "stdio.h"
#include "stdlib.h"
#include "count.h"
#include "readFile.h"

int main() {
  int NumberOfElements;
  FILE *inputFile;
  inputFile = fopen("input.txt", "r");
  //TODO Check file existance
  read_from_file(&NumberOfElements, inputFile);
  int *memory = NULL;
  memory = malloc(NumberOfElements * sizeof(int));

  if (memory == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    //TODO define ALLOCERROR
    return -1;
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
