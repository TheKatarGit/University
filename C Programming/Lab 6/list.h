#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct data{
  char model[20];
  int price;
} data_t;

struct MyList_node{
  data_t* data;
  struct MyList_node *next;
};

struct MyList_node* fill_list(struct MyList_node *start,FILE* f);
void print_list(struct MyList_node *start);
struct MyList_node* add_front(struct MyList_node *start, struct MyList_node *node);
struct MyList_node* create_node(char *model, int price);
struct MyList_node* pop_front(struct MyList_node *start);
data_t* pop_end(struct MyList_node *start);
struct MyList_node reverse(struct MyList_node *start);
struct MyList_node insert_sort(struct MyList_node *start);
