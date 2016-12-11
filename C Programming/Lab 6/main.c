#include "list.h"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Insufficient arguments\n");
    return 0;
  }
  struct MyList_node *start;
  FILE *f = fopen(argv[1], "r");
  if (!f) {
    printf("Couldn't open file\n");
    return 0;
  }
  puts("OK?");
  start = fill_list(start, f);
  puts("OK?");
  fclose(f);
  print_list(start);
  printf("%s\n", pop_front(start)->model);

  printf("\n%d\n",pop_end(start)->price);
  print_list(start);
  return 0;
}
