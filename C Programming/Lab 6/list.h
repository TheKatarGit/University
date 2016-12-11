#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Mylist_node{
  (void*) data_t data;
  struct Mylist_node *next;
};

typedef struct data{
  char model[20];
  int price;
} data_t;

void fill_list(struct Mylist_node *start,FILE* f);
void print_list(struct Mylist_node *start);

struct MyList_node pop_front(struct Mylist_node *start);
struct MyList_node pop_end(struct Mylist_node *start);
struct MyList_node reverse(struct Mylist_node *start);
struct MyList_node insert_sort(struct Mylist_node *start);