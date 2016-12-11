
struct list_node* create_node(char *model, int price){
    struct list_node *node = malloc(sizeof(struct list_node))
    if (node){
        strcpy(node->data->model, model);
        node->data->price = price;
        node->next = NULL;
    }
    return node;
}



void fill_list(struct Mylist_node *start,FILE* f){
  char model[20];
  int price;
  while (!feof(f)) {
      fscanf(f, "%s", &model);
      fscanf(f, "%d", &price);
      struct MyList_node *node = create_node(model, price);
      start->next = node;
  }
}

void print_list(struct Mylist_node *start){
  printf("List:\n");
  for ( ; start; start = start->next){
			printf("\nModel - %s\nPrice - %d\n\n",start->data->model,start->data->price);
	}
  printf("\n");
}
