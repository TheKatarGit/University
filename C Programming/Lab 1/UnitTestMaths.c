#include "UnitTestMaths.h"
#include "maths.h"
#include <stdlib.h>
#include "stdio.h"

struct Tests {
  int ArrayCount;
  float AvgExpected;
  float AvgRecieved;
  float Array[100];
};

int UnitTestMaths() {
  printf("\nTesting maths.h...\n");
  struct Tests Test1={10,5,0,{1,2,3,4,5,6,7,8,9,10}};
  struct Tests Test2 = {7,1,0,{1,1,1,1,1,1,1}};
  struct Tests Test3 = {6,20,0,{0.75,-3.21,65,32.53,0,31}};
  get_average(Test1.Array, &Test1.ArrayCount, &Test1.AvgRecieved);
  get_average(Test2.Array, &Test2.ArrayCount, &Test2.AvgRecieved);
  get_average(Test3.Array, &Test3.ArrayCount, &Test3.AvgRecieved);
  int Test1Res, Test2Res,Test3Res;
  if (Test1.AvgExpected == Test1.AvgRecieved){
    printf("Test 1 : OK\n");
    Test1Res = 1;
  }
  else{
    printf("Test 1 : Failed\n");
    Test1Res = 0;
  }
  if (Test2.AvgExpected == Test2.AvgRecieved){
    printf("Test 2 : OK\n");
    Test2Res = 1;
  }
  else{
    printf("Test 2 : Failed\n");
    Test2Res = 0;
  }
  if (Test3.AvgExpected == Test3.AvgRecieved){
    printf("Test 3 : OK\n");
    Test3Res = 1;
  }
  else{
    printf("Test 3 : Failed\n");
    Test3Res = 0;
  }
  return Test1Res && Test2Res && Test3Res;
}
