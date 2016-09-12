#include "stdio.h"
#include "stdlib.h"

int read_from_file(float ArrayOfNumbers[])
{
  int i;
  FILE *numbers;
  numbers = fopen("old_numbers.txt", "r");
  for (i = 0; i < 100; i++) {
    fscanf(numbers, "%f, ", &ArrayOfNumbers[i]);
  };
  return i;
}

void print_to_files(float ArrayOfNumbers[], float avg) {
  FILE *old_numbers, *new_numbers;
  old_numbers = fopen("old_numbers.txt", "w");
  for (int i = 0; i < 100; i++) {
    fprintf(numbers, "%f, ", ArrayOfNumbers[i]);
  };
}
