#include "InOut.h"

struct Tests{
  int ArrayCounterGot;
  int ArrayCounterExpected;
  float ArrayGot[];
  float ArrayExpected[];
}

int UnitTestScan(){
  struct Tests Test1 = {0,10,0,{1,2,3,4,5,6,7,8,9,10}}
  struct Tests Test2 = {0,7,0,{0.72,12,-4,-5.71,0,12,45}}

  read_from_file()
}
