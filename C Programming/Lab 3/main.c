#include "list.h"
#include <assert.h>
#include "stdio.h"
#include "stdlib.h"
#include "readFile.h"
#include "replacer.h"


int main(int argc, char const *argv[]){
  if (argc != 2){
    fprintf(stderr, "Wrong number of arguments.\n");
    return 0;
  }
  FILE *inputFile;
  int NumberOfElements = 0;
  int curr_number;
  struct list_node *head = NULL, *node;
  inputFile = fopen(argv[1],"r");
  if (!inputFile){
    fprintf(stderr, "File does not exist.\n");
    return 0;
  }
  if (countElements(&NumberOfElements, inputFile)){
    fclose(inputFile);
    return 0;
  }
  for (size_t i = 0; i < NumberOfElements; i++) {
    fscanf(inputFile, "%d ", &curr_number);
    node = create_node(curr_number);
    assert(node);
    head = add_end(head, node);
  }
  print(head);
  replaceElements(head);
  print(head);

  fclose(inputFile);
  free_all(head);
  return 0;
}
