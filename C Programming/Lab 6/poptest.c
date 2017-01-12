#include "list.h"



void main(){

  struct MyList_node* start = NULL;
  struct MyList_node* node;
  node = create_node("egor", 20);
  start = add_front(start,node);
  node = create_node("egur", 21);
  start = add_front(start,node);
  node = create_node("eger", 10);
  start = add_front(start,node);

  if(!(pop_end(NULL))){puts("Pop end rejected NULL! Test passed.");}
  if(!(pop_front(NULL))){puts("Pop front rejected NULL! Test passed.");}

  //print_list(start);

  if(pop_end(start)->price == 20){puts("Pop end returned correct result. Test Passed.");}
  if(pop_front(start)->price == 10){puts("Pop front returned correct result. Test Passed.");}

  return;

}