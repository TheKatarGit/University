#include "stdio.h"

struct CustomNumber {
  int mantissa[30];
  int power[5];
};


int main(int argc, char const *argv[]) {
  char string[100];
  struct CustomNumber number1 = {0,0}, number2 = {0,0};
  scanf("%s",string );
  int i = 0;

  while (string[i] != 'e'){
    number1.mantissa[i] = (int) string[i] - 48;
    i++;
  }
  printf("Mantiss: ");
  for (size_t k = 0; k < 30; k++) {
    printf("%d",number1.mantissa[k] );
  }
  printf("\n");

  printf("%d\n",i );

  for (size_t j = 0; j < 5; j++) {
    number1.power[j] = (int) string[i] - 48;
    i++;
  }

  printf("Power: ");
  for (size_t k = 0; k < 5; k++) {
    printf("%d",number1.power[k] );
  }
  printf("\n");

  return 0;
}
