#include "ISOlib.h"

char *remove_extra_spaces(char *string, int string_length) {
    int i = 0;
    int j = 0;
    char *new_string = malloc(string_length*sizeof(char));
    while (i < string_length) {
        if (isspace(string[i])){
            new_string[j] = string[i];
            while ((isspace(string[i]))) {
                i++;
            }

        }
        else{
            new_string[j] = string[i];
            i++;
        }
        j++;
    }
    return new_string;
}

void replace_commas(char *string, int string_length) {
    /* code */
}

void capitalize_beginning(char *string, int string_length) {
    /* code */
}
