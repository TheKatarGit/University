#include "readFile.h"
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
