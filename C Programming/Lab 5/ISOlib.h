#ifndef _STR_H_
#define _STR_H_
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"


#define _END_OF_FILE_ -1
#define _FILE_ERR_ NULL

char *remove_extra_spaces(char *string, int string_length);

char *replace_commas(char *string, int string_length);

char *read_str(FILE *f);

char *capitalize_beginning(char *string, int string_length);

#endif //_STR_H_
