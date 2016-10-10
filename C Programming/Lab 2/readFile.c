#include "readFile.h"
int read_from_file(int *NumberOfElements, FILE *numbers)
{
  int Number;
  int elementsCounter = 0;
  int res = fscanf(numbers, "%d ", &Number);

  while (res != EOF) {
    elementsCounter++;
    res = fscanf(numbers, "%d ", &Number);
    if ((res != 1) && (res != EOF)){
      fprintf(stderr, "File contains incorrect elements. \n" );
      return BADEL;
    }

  }
  if (elementsCounter == 0){
    fprintf(stderr, "File is empty\n");
    return FILE_EMPTY;
  }

  *NumberOfElements = elementsCounter;
  return 0;
}

int read_to_mem(int *memStart, int *memEnd, FILE* file){
  if ((memStart == NULL)){
    printf("Memory start is NULL.\n");
    return MEMNULL;
  };
  if ((memEnd == NULL)){
    printf("Memory end is NULL.\n");
    return MEMNULL;
  };
  if ((file == NULL)){
    printf("File is NULL.\n");
    return MEMNULL;
  };

  while (memStart != memEnd) {
    fscanf(file, "%d ", memStart);
    memStart++;
  }
  return 0;
}
