#include "list.h"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Insufficient arguments\n");
    return 0;
  }
  struct Mylist_node *start;
  FILE *f = fopen(argv[1], "r");
  if (!f) {
    printf("Couldn't open file\n");
    return 0;
  }
  // fill_list(start, f);
  // fclose(f);
  // print_list(start);
  // pop_front(start);
  // print_list(start);
  // pop_end(start);
  // print_list(start);
  // reverse(start);
  // print_list(start);
  // insert_sort(start);
  // print_list(start);
  // free_list(start);
  return 0;
}
