#include "count.h"

int main(int argc, char const *argv[]) {
  int *memStart;
  int *memFinish;
  int elCount = 5;
  int testArray[5] = {1,1,1,1,1};
  memStart = testArray;
  memFinish = memStart + elCount;
  int countPosExpected = 1;
  int countPosReal = countExistance(memStart,memFinish);
  if (countPosExpected == countPosReal){
    printf("Test 1 Passed\n");
  }
  else{
    printf("Test 1 Failed\n");
  }
  elCount = 3;
  int testArray2[3] = {-1, 1, -3};
  memStart = testArray2;
  memFinish = memStart + elCount;
  countPosExpected = 3;
  countPosReal = countExistance(memStart, memFinish);
  if (countPosExpected == countPosReal){
    printf("Test 2 Passed\n");
  }
  else{
    printf("Test 2 Failed\n");
  }
  return 0;
}
