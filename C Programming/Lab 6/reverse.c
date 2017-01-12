#include "list.h"



void main(){

  struct MyList_node* start = NULL;
  struct MyList_node* start2 = NULL;
  struct MyList_node* node;
  node = create_node("egor", 20);
  start = add_front(start,node);
  node = create_node("egur", 21);
  start = add_front(start,node);
  node = create_node("eger", 10);
  start = add_front(start,node);
  node = create_node("egar", 19);
  start = add_front(start,node);

  node = create_node("egor", 20);
  start2 = add_front(start2,node);
  node = create_node("egur", 21);
  start2 = add_front(start2,node);
  node = create_node("eger", 10);
  start2 = add_front(start2,node);
  node = create_node("egar", 19);
  start2 = add_front(start2,node);

  struct MyList_node *start1 = reverse(start);
  start = reverse(start1);

  if(!reverse(NULL)){puts("OK0!");}

  int a = 1;
  for (int i = 0 ; i < 4; i++){
      if(start2->data->price != start->data->price){a = 0;}
      start2 = start2->next;
      start = start->next;
  }
  if(a){puts("OK1!");}

  return;

}
