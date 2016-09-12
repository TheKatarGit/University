#include "stdio.h"
#include "stdlib.h"

int read_from_file(float ArrayOfNumbers[])
{
  int elemetsCounter = 0;
  FILE *numbers;
  numbers = fopen("old_numbers.txt", "r");
  while (fscanf(numbers, "%f ", &ArrayOfNumbers[elemetsCounter])) {
    elemetsCounter++;
  }
  printf("%d\n", elemetsCounter);
  return elemetsCounter;
}

void print_to_files(float ArrayOfNumbers[], int elemetsCounter, float avg) {
  FILE *old_numbers, *new_numbers;
  old_numbers = fopen("old_numbers.txt", "w");
  new_numbers = fopen("new_numbers.txt","w");
  for (int i = 0; i < elemetsCounter; i++) {
    if (ArrayOfNumbers[i] < avg){
      fprintf(new_numbers, "%f, ", ArrayOfNumbers[i]);
    }
    else{
      fprintf(old_numbers, "%f, ",ArrayOfNumbers[i]);
    }
  };
}
