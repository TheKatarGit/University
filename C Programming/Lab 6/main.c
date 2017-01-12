#include "list.h"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Insufficient arguments\n");
    return 0;
  }


  struct MyList_node *start = NULL;

  FILE *f = fopen(argv[1], "r");
  if (!f) {
    printf("Couldn't open file\n");
    return 0;
  }
  puts("FILL LIST?");
  start = fill_list(start, f);
  puts("PRINT LIST?");
  fclose(f);
  puts("OK?");
  print_list(start);
  puts("REVERSE LIST?");
  start = reverse(start);
  print_list(start);
  puts("POP END?");
  data_t* temp1 = pop_end(start);
  data_t* temp2 = pop_front(start);

  printf("\n%d\n",temp1->price);
  puts("POP FRONT?");
  printf("\n%d\n",temp2->price);
  print_list(start);
  puts("INSERTION SORT?");
  start = insertion_sort(start);
  print_list(start);
  free_all(start);
  puts("OK?");
  free(temp1);
  free(temp2);
  printf("HA %d\n",sizeof(data_t));
  return 0;
}
