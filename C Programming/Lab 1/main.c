#include <stdio.h>
#include "InOut.h"
#include "maths.h"
#include "unittests.h"
#include "delete.h"
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float ArrayOfNumbers[100];
  int NumberOfElements = 0;
  float avg = 0;
  FILE *numbers, *new_numbers;
  numbers = fopen("old_numbers.txt", "r");
  if (numbers != NULL){
    read_from_file(ArrayOfNumbers, &NumberOfElements, numbers);
    fclose(numbers);
    if (NumberOfElements != 0){
      get_average(ArrayOfNumbers, &NumberOfElements, &avg);
      numbers = fopen("old_numbers.txt","w");
      new_numbers = fopen("new_numbers.txt","w");
      print_to_files(ArrayOfNumbers, &NumberOfElements, &avg, numbers, new_numbers);
      fclose(numbers);
      fclose(new_numbers);
    }
    else{
      printf("File doesn't contain numbers\n");
    }
  }
  else{
    printf("No file found\n");
  }



  return 0;
}
