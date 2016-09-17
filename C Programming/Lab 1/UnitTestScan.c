#include <stdlib.h>
#include "stdio.h"
#include "InOut.h"

struct Tests{
  int ArrayCounterGot;
  int ArrayCounterExpected;
  float ArrayGot[100];
  float ArrayExpected[100];
};

int UnitTestScan(){
  printf("\nTesting InOut.h... \n");
  struct Tests Test1 = {0,10,{0},{1,2,3,4,5,6,7,8,9,10}};
  struct Tests Test2 = {0,7,{0},{0.72,12,-4,-5.71,0,12,45}};
  FILE *test1;
  FILE *test2;
  test1 = fopen("test1.txt", "r");
  test2 = fopen("test2.txt", "r");
  int Test1Res, Test2Res;
  read_from_file(Test1.ArrayExpected, &Test1.ArrayCounterGot, test1);
  read_from_file(Test2.ArrayExpected, &Test2.ArrayCounterGot, test2);
  if (Test1.ArrayCounterExpected == Test1.ArrayCounterGot){
    printf("Test 1 : Ok\n");
    Test1Res = 1;
  }
  else{
    printf("Test 1 : failed\n");
    Test1Res = 0;
  }
  if (Test2.ArrayCounterExpected == Test2.ArrayCounterGot){
    printf("Test 2 : Ok\n");
    Test2Res = 1;
  }
  else{
    printf("Test 2 : failed\n");
    Test2Res = 0;
  }
  fclose(test1);
  fclose(test2);
  return Test1Res && Test2Res;
}
