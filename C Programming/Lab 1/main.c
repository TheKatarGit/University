#include <stdio.h>
#include "InOut.h"
#include "maths.h"

int main(int argc, char const *argv[]) {
  float ArrayOfNumbers[100];
  int NumberOfElements = 0;
  float avg = 0;
  read_from_file(ArrayOfNumbers, &NumberOfElements);
  get_average(ArrayOfNumbers, &NumberOfElements, &avg);
  print_to_files(ArrayOfNumbers, &NumberOfElements, &avg);
  return 0;
}
