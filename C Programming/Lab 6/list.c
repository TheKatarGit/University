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
      if (fscanf(f, "%s %d", model, &price) == 2){
        node = create_node(model, price);
        start = add_front(start,node);
      }
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


struct MyList_node* insert(struct MyList_node* begin, struct MyList_node* position, struct MyList_node* new_Item){
   //check if we add to the beginning
   if(begin == position) {
       new_Item->next = begin;
       return new_Item;
   }
   struct MyList_node* pom = begin;
   while(pom->next != position) {
       pom = pom->next;
   }
   new_Item->next = pom->next;
   pom->next = new_Item;
   return begin;
}

void free_all(struct MyList_node* start){
  struct MyList_node *next;

  for ( ; start; start = next){
      puts("kek");
      next = start->next;
      free(start->data);
      free(start);
  }
}



struct MyList_node* insertion_sort(struct MyList_node* begin){
   struct MyList_node* sorted = begin;
   struct MyList_node* preaktual = begin;
   struct MyList_node* pom;
   struct MyList_node* pom1;

   while(preaktual->next != NULL) {
       pom = sorted;
	   while( preaktual->next  != NULL && pom != preaktual->next && pom->data->price < preaktual->next->data->price)
        pom = pom->next;
       if(preaktual->next != pom) {
           pom1 = preaktual->next;
           preaktual->next = preaktual->next->next;
           sorted = insert(sorted, pom, pom1);
       }
       else{
        preaktual = preaktual->next;
       }
   }
   return sorted;
}
