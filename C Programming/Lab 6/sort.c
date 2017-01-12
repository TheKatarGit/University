#include "list.h"



void main(){

  struct MyList_node* start = NULL;
  struct MyList_node* start1 = NULL;
  struct MyList_node* node;

  if(!insertion_sort(NULL)){puts("Insertion sort rejected NULL. Test passed.");}

  node = create_node("egor", 20);
  start = add_front(start,node);
  node = create_node("egur", 21);
  start = add_front(start,node);
  node = create_node("eger", 10);
  start = add_front(start,node);

  node = create_node("egur", 21);
  start1 = add_front(start1,node);
  node = create_node("egor", 20);
  start1 = add_front(start1,node);
  node = create_node("eger", 10);
  start1 = add_front(start1,node);

  start = insertion_sort(start);

  print_list(start);
  print_list(start1);

  int a = 1;
  for (int i = 0 ; i < 3; i++){
      if(start1->data->price != start->data->price){a = 0;}
      start1 = start1->next;
      start = start->next;
  }
  if(a){puts("List sorted correctly. Test Passed.");}

  return;

}
