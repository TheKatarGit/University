#include "list.h"
#include "stdio.h"
#include "replacer.h"
#include "assert.h"

int main(int argc, char const *argv[]) {
  struct list_node *head = NULL, *node;
  // for (size_t i = 1; i <= 10; i++) {
  //   node = create_node(1);
  //   assert(node);
  //   head = add_end(head, node);
  // }

  node = create_node(1);
  head = add_end(head, node);
  node = create_node(5);
  head = add_end(head, node);
  node = create_node(1);
  head = add_end(head, node);
  node = create_node(5);
  head = add_end(head, node);

  int res_array[4] = {5,1,1,5};
  int res_array_got[4] = {0};
  int i = 0;
  replaceElements(head);
  for ( ; head; head = head->next){
    res_array_got[i] = head->num;
    i++;
  }
  for (size_t i = 0; i < 4; i++) {
    printf("Result arr[%d]: %d Expected arr[%d]: %d\n",i,res_array_got[i],i,res_array[i]);
    if (res_array_got[i] != res_array[i]){
      printf("Test failed");
      return 0;
    }
  }
  printf("Test successful\n");
  return 0;
}
