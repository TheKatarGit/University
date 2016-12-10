#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

char *remove_extra_spaces(char *string, int string_length);

char *replace_commas(char *string, int string_length);

char *read_str(FILE *f);

char *capitalize_beginning(char *string, int string_length);
