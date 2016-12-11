#include "list.h"

struct MyList_node* create_node(char *model, int price){
    struct MyList_node *node = malloc(sizeof(struct MyList_node));
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


data_t* pop_front(struct MyList_node *start){
  struct MyList_node* temp = start;
  data_t *data = start->data;
  free(start);
  *start = *temp->next;
  return data;
}

data_t* pop_end(struct MyList_node *start){
  struct MyList_node *temp;
  while(start->next){
    if(start->next->next == NULL){temp = start;}
    start = start->next;
  }
  data_t* data = start->data;
  free(start);
  temp->next = NULL;
  return data;
}

struct MyList_node* reverse(struct MyList_node* root) {
  struct MyList_node* new_root = NULL;
  while (root) {
    struct MyList_node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}
