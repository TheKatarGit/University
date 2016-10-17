#include "generator.h"
#include "seeker.h"
#include "stdio.h"
#include "string.h"
#include "stack.h"
#include "terminalgui.h"


int main(int argc, char const *argv[]) {
  int Exit = 1;
  clock_t start, end;
  char choice;
  int stack_created = 0;
  Stack_t *stack;
  while (Exit) {
    printf("Make a choice, Neo: \n");
    choice = getchar();
    clean_stdin();
    switch (choice) {
      case 'l':
        printf("Starting maze generation...\n");
        start_labyrinth();
        clean_stdin();
        break;
      case 's':
        start = clock();
        stack = calloc(1, sizeof(Stack_t));
        end = clock();
        stack_created = 1;
        printf("Stack initialised.\n");
        printf("Time needed for stack initialisation is %lf\n",(double)(end - start));
        break;
      case 'p':
        if (stack_created){
          int x,y;
          printf("Choose a point to be pushed into stack: ");
          scanf("%d %d", &x, &y);
          clean_stdin();
          Cell_t point;
          point.x = x;
          point.y = y;
          start = clock();
          push(point, stack);
          end = clock();
          printf("Time needed for pushing int a stack is %lf\n",(double)(end - start));
          printf("Point pushed.\n");
        }
        else{
          printf("Create a stack first!\n");
        }
        break;
      case 'o':
        if ((stack_created) && (stack->top != NULL)){
          start = clock();
          pop(stack);
          end = clock();
          printf("Time needed for popping an element from a the stack is %lf\n",(double)(end - start));
          printf("Stack popped.\n");
        }
        else{
          printf("Create a stack first!\n");
        }
        break;
      case 'w':
        if (stack_created){
          start = clock();
          wipe(stack);
          free(stack);
          end = clock();
          stack_created = 0;
          printf("Time needed for wiping and freeing a stack is %lf\n",(double)(end - start));
          printf("Stack wiped\n");
        }
        else{
          printf("Create a stack first!\n");
        }
        break;
      case 'e':
        if (stack_created){
          wipe(stack);
          free(stack);
        }
        Exit = 0;
        break;
      default:
        printf("This is not an option.\n");
        break;
    }
  }


  return 0;
}
