#include "maths.h"

void get_average(float ArrayOfNumbers[], int *i, float *avg)
{
  int j;
  int sum = 0;
    for (j = 0; j < *i; j++) {
      sum += ArrayOfNumbers[j];
    }
  *avg = sum/(*i);
}
