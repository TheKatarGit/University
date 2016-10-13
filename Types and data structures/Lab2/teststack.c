#include "stack.h"
#include "types.h"

int main(int argc, char const *argv[]) {
  Stack_t *teststack = calloc(1, sizeof(Stack_t));
  Cell_t testcell;
  // teststack->size = 2;
  testcell.x = 1;
  testcell.y = 1;

  Cell_t testcell2;
  testcell2.x = 1;
  testcell2.y = 1;

  push(testcell,teststack);
  push(testcell2, teststack);
  pop(teststack);
  push(testcell2, teststack);
  wipe(teststack);
  free(teststack);
  return 0;
}
