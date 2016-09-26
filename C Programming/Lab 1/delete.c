#include "delete.h"
#include "stdlib.h"
#include "stdio.h"

void delete_from_array(float *ArrayOfNumbers, int *elementsCounter, int start_point) {
  if (start_point < *elementsCounter){
    for (size_t move_pos = start_point; move_pos < *elementsCounter - 1; move_pos++) {
      ArrayOfNumbers[move_pos] = ArrayOfNumbers[move_pos + 1];
    }
  }
}
