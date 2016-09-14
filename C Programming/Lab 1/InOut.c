#include "stdio.h"
#include "stdlib.h"
#include "InOut.h"

void read_from_file(float ArrayOfNumbers[], int *NumberOfElements, FILE* numbers)
{
  int elemetsCounter = 0;
  while (fscanf(numbers, "%f ", &ArrayOfNumbers[elemetsCounter]) != EOF) {
    elemetsCounter++;
  }
  *NumberOfElements = elemetsCounter;
}

void print_to_files(float ArrayOfNumbers[], int *elemetsCounter, float *avg, FILE* numbers, FILE* new_numbers) {
  for (int i = 0; i < *elemetsCounter; i++) {
    if (ArrayOfNumbers[i] < *avg){
      fprintf(new_numbers, "%f, ", ArrayOfNumbers[i]);
    }
    else{
      fprintf(numbers, "%f, ",ArrayOfNumbers[i]);
    }
  };
}
