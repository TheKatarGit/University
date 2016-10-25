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
  void *save;
  int stack_created = 0;
  Stack_t *stack;

  printf("Types and data structrures. Lab #2 \n");
  printf("by N.Brodov & D.Mikhalkovich\n\n");


  while (Exit)
  {

    printf("Available commands: \n");
    printf("s - initialize stack\n");
    printf("p - add element to stack\n");
    printf("o - delete element from stack\n");
    printf("w - clear the stack\n");
    printf("r - print current stack\n");
    printf("l - start maze generator and solver\n");
    printf("c - compare array and stack implementation\n");
    printf("e - exit\n\n");

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
        save = &stack;
        end = clock();
        stack_created = 1;
        printf("----------------\n");
        printf("Stack initialised.\n");
        printf("Time needed for stack initialisation is %lf\n",(double)(end - start));
        printf("Stack begins at %p\n",stack);
        printf("----------------\n");
        break;
      case 'p':
        if (stack_created)
        {
          int x,y,flag = 0;
          printf("Choose a point (x; y - int) to be pushed into stack: ");
          do
          {
            flag = scanf("%d %d", &x, &y);
            if (!flag)
            {
              printf("Wrong input!\n");
              printf("Choose a point (x; y - int) to be pushed into stack: ");
            }
          } while (!flag);
          clean_stdin();
          Cell_t point;
          point.x = x;
          point.y = y;
          start = clock();
          push(point, stack);
          save = &stack;
          end = clock();
          printf("----------------\n");
          printf("Time needed for pushing int a stack is %lf\n",(double)(end - start));
          printf("Point pushed.\n");
          printf("Now stack begins at %p\n",stack->top);
          printf("----------------\n");
        }
        else
        {
          printf("----------------\n");
          printf("Create a stack first!\n");
          printf("----------------\n");
        }
        break;
      case 'o':
        if ((stack_created) && (stack->top != NULL))
        {
          printf("Removing Node at adress %p...\n",stack->top);
          start = clock();
          pop(stack);
          end = clock();
          printf("----------------\n");
          printf("Time needed for popping an element from a the stack is %lf\n",(double)(end - start));
          printf("Element popped.\n");
          printf("----------------\n");
        }
        else if (stack->top == NULL)
        {
          printf("----------------\n");
          printf("Stack is empty! \n");
          printf("----------------\n");
        }
        else
        {
          printf("----------------\n");
          printf("Create a stack first!\n");
          printf("----------------\n");
        }
        break;
      case 'w':
        if (stack_created)
        {
          start = clock();
          wipe(stack);
          free(stack);
          end = clock();
          stack_created = 0;
          printf("----------------\n");
          printf("Time needed for wiping and freeing a stack is %lf\n",(double)(end - start));
          printf("Stack wiped\n");
          printf("----------------\n");
        }
        else
        {
          printf("----------------\n");
          printf("Create a stack first!\n");
          printf("----------------\n");
        }
        break;
      case 'r':
        if (stack_created){
          print(stack);
          // clean_stdin();
        }
        else
        {
          printf("----------------\n");
          printf("Create a stack first!\n");
          printf("----------------\n");
        }
        break;
      case 'c':
        printf("----------------\n");
        compare();
        printf("----------------\n");
        break;
      case 'e':
        if (stack_created)
        {
          wipe(stack);
          free(stack);
        }
        Exit = 0;
        break;
      default:
        printf("----------------\n");
        printf("This is not an option.\n");
        printf("----------------\n");
        break;
    }

  }


  return 0;
}
