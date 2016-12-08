#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Mylist_node{
  string model;
  int price;
  struct Mylist_node *next;

};

void fill_list(struct Mylist_node *start,FILE* f);
void print_list(struct Mylist_node *start);

struct MyList_node pop_front(struct Mylist_node *start);
struct MyList_node pop_end(struct Mylist_node *start);
struct MyList_node reverse(struct Mylist_node *start);
struct MyList_node insert_sort(struct Mylist_node *start);
