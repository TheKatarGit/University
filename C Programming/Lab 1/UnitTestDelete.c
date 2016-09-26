#include "delete.h"
#include "stdlib.h"
#include "stdio.h"

struct Tests{
  int StartPoint;
  int ArrayGotLen;
  int ArrayExpectedLen;
  float ArrayGot[100];
  float ArrayExpected[100];
};

int UnitTestDelete() {
  printf("\nTesting delete.c ...\n" );

  struct Tests test1 = {2,5,4, {1,2,3,4,5}, {1,2,4,5}};
  struct Tests test2 = {0,6,5, {2,3,4,5,6,7}, {3,4,5,6,7}};
  struct Tests test3 = {5,4,4, {1,2,3,4}, {1,2,3,4}};
  delete_from_array(test1.ArrayGot, &test1.ArrayGotLen, test1.StartPoint);
  delete_from_array(test2.ArrayGot, &test2.ArrayGotLen, test2.StartPoint);
  delete_from_array(test3.ArrayGot, &test3.ArrayGotLen, test3.StartPoint);
  int Test1Res = 1, Test2Res = 1, Test3Res = 1;
  for (size_t i = 0; i < test1.ArrayExpectedLen; i++) {
    if (test1.ArrayGot[i] != test1.ArrayExpected[i]){

      Test1Res = 0;
    }
  }
  if (Test1Res){
    printf("Test 1 : OK\n");
  }
  else{
    printf("Test 1 Failed\n");
  }
  for (size_t i = 0; i < test2.ArrayExpectedLen; i++) {
    if (test2.ArrayGot[i] != test2.ArrayExpected[i]){
      Test2Res = 0;
    }
  }
  if (Test2Res){
    printf("Test 2 : OK\n");
  }
  else{
    printf("Test 2 Failed\n");
  }
  for (size_t i = 0; i < test3.ArrayExpectedLen; i++) {
    if (test3.ArrayGot[i] != test3.ArrayExpected[i]){
      Test3Res = 0;
    }
  }
  if (Test3Res){
    printf("Test 3 : OK\n");
  }
  else{
    printf("Test 3 Failed\n");
  }
  return Test1Res && Test2Res && Test3Res;
}
