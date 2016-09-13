#include "InOut.h"
#include "maths.h"
#include "stdlib.h"

struct Tests {
  int *ArrayCount;
  float AvgExpected;
  float *AvgRecieved;
  float *Array[];
};

int UnitTestMaths() {
  struct Tests Test1, Test2, Test3;

  *Test1.ArrayCount = 10;
  *Test1.Array = (float*) malloc( sizeof(float) * (*Test1.ArrayCount));
  *Test1.Array[10] = {1,2,3,4,5,6,7,8,9,10};
  Test1.AvgExpected = 0;
  *Test1.AvgRecieved = 0;


  *Test2.ArrayCount = 7;
  *Test2.Array = (float*) malloc( sizeof(float) * (*Test1.ArrayCount));
  Test2.Array[7] = {1,1,1,1,1,1,1};
  Test2.AvgExpected = 0;
  *Test2.AvgRecieved = 0;


  *Test3.ArrayCount = 6;
  *Test3.Array = (float*) malloc( sizeof(float) * (*Test1.ArrayCount));
  Test3.Array[6] = {0.75,-3.21,65,32.53,0,31};
  Test3.AvgExpected = 0;
  *Test3.AvgRecieved = 0;

  get_average(Test1.Array, Test1.ArrayCount, Test1.AvgRecieved);

  free(Test1.Array)
  return 0;
}
