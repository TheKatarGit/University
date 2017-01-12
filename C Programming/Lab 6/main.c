#include "list.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("Insufficient arguments\n");
    return 0;
  }


  struct MyList_node *start = NULL;

  FILE *f = fopen(argv[1], "r");
  if (!f) {
    printf("Couldn't open file\n");
    return 0;
  }
  start = fill_list(start, f);
  fclose(f);
  print_list(start);

  if (!strcmp(argv[2], "M")) {
  start = reverse(start);
  print_list(start);
  data_t* temp1 = pop_end(start);
  data_t* temp2 = pop_front(start);
  printf("\nPopped %d from end\n",temp1->price);
  printf("\nPopped %d from front\n",temp2->price);
  print_list(start);
  start = insertion_sort(start);
  print_list(start);
  free_all(start);
  free(temp1);
  free(temp2);
  return 0;
}
  else if (!strcmp(argv[2], "F")){
    printf("Pop Front\n");
    data_t* temp = pop_front(start);
    printf("\nPopped %d from front\n",temp->price);
    print_list(start);
    free_all(start);
    free(temp);
    return 0;
  }

  else if (!strcmp(argv[2], "E")){
    printf("Pop End\n");
    data_t* temp = pop_end(start);
    printf("\nPopped %d from end\n",temp->price);
    print_list(start);
    free_all(start);
    return 0;
  }
  else if (!strcmp(argv[2], "S")){
    printf("Sort\n");
    start = insertion_sort(start);
    print_list(start);
    free_all(start);
    return 0;
  }
  else if (!strcmp(argv[2], "R")){
    printf("Reverse\n");
    start = reverse(start);
    print_list(start);
    free_all(start);
    return 0;
  }
  else {
    printf("Unknown Argument\n");
    return 0;
  }
}
