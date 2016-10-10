#include "readFile.h"

int main() {
  FILE* file;
  printf("Test 1 initiating... \n");
  file = fopen("test1.txt", "r");

  int NumberOfElementsExpected = 5;
  int NumberOfElementGot1 = 0;
  if (!read_from_file(&NumberOfElementGot1, file)){
    if (NumberOfElementGot1 == NumberOfElementsExpected){
      printf("Test 1 Passed\n");
    }
    else{
      printf("Test 1 failed counting elements.\n");
    }
  }
  else{
    printf("Test 1 failed.\n");
  }
  fclose(file);
  printf("\nTest 2 initiating... \n");
  file = fopen("test2.txt","r");
  NumberOfElementsExpected = 0;
  int NumberOfElementGot2 = 0;
  if (read_from_file(&NumberOfElementGot2, file)){
    if (NumberOfElementGot2 == NumberOfElementsExpected){
      printf("Test 2 Passed\n");
    }
    else{
      printf("Test 2 failed counting elements.\n");
    }
  }
  else{
    printf("Test 2 failed.\n");
  }
  fclose(file);
  return 0;
}
