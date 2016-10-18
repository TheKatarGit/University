#include "stack.h"
#include <assert.h>

//stack functions
void push(Cell_t c, Stack_t *stack){
   Node_t *new_node = malloc(sizeof(Node_t));
   new_node->cell = c;
   new_node->next = NULL;

   if(stack->top != NULL) {
       new_node->next = stack->top;
   }

   stack->top = new_node;
   stack->size++;
}

Cell_t pop(Stack_t *stack){
    assert(stack->top != NULL);

    Cell_t  popped = stack->top->cell;
    Node_t* top    = stack->top;

    stack->top = stack->top->next;

    free(top);
    stack->size--;
    return popped;
}

void wipe(Stack_t *s){
    while(s->size) {
        pop(s);
    }
    s->top  = NULL;
    s->size = 0;
}


void print(Stack_t *stack)
{
    Node_t *temp_node = malloc(sizeof(Node_t));
    temp_node->next = stack->top;
    printf("Current Stack:\n");
    for ( ; stack->top; stack->top = stack->top->next)
        printf("%d %d \n", stack->top->cell.x, stack->top->cell.y);

    printf("\n");
    stack->top = temp_node->next;
    free(temp_node);
}
