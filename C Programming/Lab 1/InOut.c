#include "stdio.h"
#include "stdlib.h"
#include "InOut.h"
#include "delete.h"

void read_from_file(float ArrayOfNumbers[], int *NumberOfElements, FILE *numbers)
{
  int elementsCounter = 0;
  while (fscanf(numbers, "%f ", &ArrayOfNumbers[elementsCounter]) == 1) {
    elementsCounter++;
  }
  *NumberOfElements = elementsCounter;
}

void print_to_files(float ArrayOfNumbers[], int *elementsCounter, float *avg, FILE *numbers, FILE *new_numbers) {
  for (int i = 0; i < *elementsCounter; i++) {
    if (ArrayOfNumbers[i] > *avg){
      fprintf(new_numbers, "%f, ", ArrayOfNumbers[i]);
      delete_from_array(ArrayOfNumbers, elementsCounter, i);
    }
    else{
      fprintf(numbers, "%f, ",ArrayOfNumbers[i]);
    }
  };
}
