#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include "types.h"
#include <string.h>


void   push(Cell_t c, Stack_t *stack);
Cell_t pop (Stack_t *stack);
void   wipe(Stack_t *stack);
void print(Stack_t *stack);
#endif // STACK_H
