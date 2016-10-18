#include "readFile.h"
int countElements(int *NumberOfElements, FILE *numbers)
{
  int Number;
  int elementsCounter = 0;
  while (1) {
    int res = fscanf(numbers, "%d ", &Number);
    if (res == EOF){
      break;
    }
    else if (res != 1){
      fprintf(stderr, "File has incorrect characters\n");
      return FILE_INCORRECT;
    }
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
