void fill_list(struct Mylist_node *start,FILE* f){
  while (!feof(f)) {
      // start->data->model,
  }

}

void print_list(struct Mylist_node *start){
  printf("List:\n");
  for ( ; start; start = start->next){
			printf("\nModel - %s\nPrice - %d\n\n",start->data->model,start->data->price);
	}
  printf("\n");
}
