#include "count.h"

int countExistance(int *memStart, int *memFinish) {
  if ((memStart == NULL) || (memFinish == NULL)){
    fprintf(stderr, "Wrong pointer recieved\n");
    return WRONG_POINTER;
  }
  int uniqueElementsCounter = 0;
  int elementOccurence = 0;
  int *temp;
  while (memStart != memFinish) {
    temp = memStart;
    while (temp != memFinish){
      if (*temp == *memStart){
        elementOccurence++;
      }
      temp++;
    }
    if (elementOccurence == 1){
      uniqueElementsCounter++;
    }
    elementOccurence = 0;
    memStart++;
  }
  return uniqueElementsCounter;
}
