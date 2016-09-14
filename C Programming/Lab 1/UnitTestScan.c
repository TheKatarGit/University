#include "stdlib.h"
#include "InOut.h"

struct Tests{
  int ArrayCounterGot;
  int ArrayCounterExpected;
  float ArrayGot[100];
  float ArrayExpected[100];
}

int UnitTestScan(){
  struct Tests Test1 = {0,10,0,{1,2,3,4,5,6,7,8,9,10}};
  struct Tests Test2 = {0,7,0,{0.72,12,-4,-5.71,0,12,45}};
  FILE* test1;
  FILE* test2;
  int Test1Res, Test2Res;
  read_from_file(Test1.ArrayExpected, &Test1.ArrayCounterExpected, test1);
  read_from_file(Test2.ArrayExpected, &Test2.ArrayCounterExpected, test1);
  if (Test1.ArrayCounterExpected == Test1.ArrayCounterGot) && (Test1.ArrayGot == Test1.ArrayExpected){
    printf("Test1 : Ok\n");
    Test1Res = 1;
  }
  else{
    printf("Test1 : failed\n");
    Test1Res = 0;
  }
  if (Test2.ArrayCounterExpected == Test2.ArrayCounterGot) && (Test2.ArrayGot == Test2.ArrayExpected){
    printf("Test2 : Ok\n");
    Test2Res = 1;
  }
  else{
    printf("Test2 : failed\n");
    Test2Res = 0;
  }
  return Test1Res && Test2Res;
}
