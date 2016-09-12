#include "stdio.h"
#include "InOut.h"
#include "maths.h"
int main()
{
  float ArrayOfNumbers[100];
  int NumberOfElements;
  NumberOfElements = read_from_file(ArrayOfNumbers);
  float avg = get_avegarge(ArrayOfNumbers, NumberOfElements);
  print_to_files(ArrayOfNumbers, NumberOfElements, avg);
  return 0;
}
