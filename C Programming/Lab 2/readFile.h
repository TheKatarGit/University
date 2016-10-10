#include "stdio.h"
#include "stdlib.h"

#define FILE_EMPTY -1
#define MEMNULL -2
#define BADEL -3


int read_from_file(int *NumberOfElements, FILE *numbers);
int read_to_mem(int *memStart, int *memEnd, FILE* file);
