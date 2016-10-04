#include "list.h"
#include <assert.h>
#include "stdio.h"
#include "stdlib.h"
#include "readFile.h"
#include "replacer.h"
int main(int argc, char const *argv[]){
  FILE *inputFile;
  int NumberOfElements = 0;
  int curr_number;
  struct list_node *head = NULL, *node;

  inputFile = fopen("input.txt","r");
  countElements(&NumberOfElements, inputFile);

  for (size_t i = 0; i < NumberOfElements; i++) {
    fscanf(inputFile, "%d ", &curr_number);
    node = create_node(curr_number);
    assert(node);
    head = add_front(head, node);
  }

  replaceElements(head);
  print(head);

  fclose(inputFile);
  free_all(head);
  return 0;
}
