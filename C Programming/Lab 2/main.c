#include "stdio.h"
#include "stdlib.h"


int read_from_file(int *NumberOfElements, FILE *numbers)
{
  int Number;
  int elementsCounter = 0;
  while (fscanf(numbers, "%d ", &Number) == 1) {
    elementsCounter++;
  }
  *NumberOfElements = elementsCounter;
  return 0;
}

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
    printf("%d\n", *memBegin);
    memBegin++;
  }
  return 0;
}
