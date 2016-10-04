#include "readFile.h"
int countElements(int *NumberOfElements, FILE *numbers)
{
  int Number;
  int elementsCounter = 0;
  while (fscanf(numbers, "%d ", &Number) == 1) {
    elementsCounter++;
  }
  if (elementsCounter == 0){
    fprintf(stderr, "File is empty\n");
    return FILE_EMPTY;
  }
  *NumberOfElements = elementsCounter;
  rewind(numbers);
  return 0;
}
