#include "stdio.h"
#include "InOut.h"
#include "maths.h"
int main()
{
  float ArrayOfNumbers[100];
  int NumberOfElements = 0;
  float avg = 0;
  read_from_file(ArrayOfNumbers, &NumberOfElements);
  get_avegarge(ArrayOfNumbers, &NumberOfElements, &avg);
  print_to_files(ArrayOfNumbers, &NumberOfElements, &avg);
  return 0;
}
