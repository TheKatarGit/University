#include "list.h"


struct MyList_node* create_node(char *model, int price){
    struct MyList_node *node = malloc(sizeof(struct MyList_node));
    //puts("OK?5");
    if (node){
        node->data = malloc(sizeof(data_t));
        strcpy(node->data->model, model);
        node->data->price = price;
        node->next = NULL;
    }
    //puts("OK?");
    return node;
}

struct MyList_node* add_front(struct MyList_node *start, struct MyList_node *node)
{
    node->next = start;

    return node;

}

struct MyList_node* fill_list(struct MyList_node *start,FILE* f){
  char model[20];
  int price;
  struct MyList_node *node;
  //puts("OK?1");
  while (!feof(f)) {
      //puts("OK?2");
      fscanf(f, "%s", model);
      fscanf(f, "%d", &price);
      //puts("OK?3");
      node = create_node(model, price);
      start = add_front(start,node);
  }
  return start;
}

void print_list(struct MyList_node *start){
  printf("List:\n");
  for ( ; start; start = start->next){
			printf("\nModel - %s\nPrice - %d\n\n",start->data->model,start->data->price);
	}
  printf("\n");
}
