#include "UnitTestMaths.h"
#include "UnitTestScan.h"
#include "UnitTestDelete.h"
#include "unittests.h"
#include "stdio.h"
#include <stdlib.h>

int main() {
  int MathsRes = UnitTestMaths();
  int ScanRes = UnitTestScan();
  int DelRes = UnitTestDelete();
  if (MathsRes && ScanRes && DelRes) {
    printf("All tests passed.\n");
    return 1;
  }
  else{
    printf("\nOne or more of tests failed. See logs.\n");
    return 0;
  }

}
