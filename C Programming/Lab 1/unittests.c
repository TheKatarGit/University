#include "UnitTestMaths.h"
#include "UnitTestScan.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  int MathsRes = UnitTestMaths();
  int ScanRes = UnitTestScan();
  if (MathsRes && ScanRes) {
    printf("All tests passed.\n");
  }
  else{
    printf("One or more of tests failed. See logs.\n");
  }
  return 0;
}
