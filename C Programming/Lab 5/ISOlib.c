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

char *replace_commas(char *string, int string_length) {
    char *new_string = malloc(string_length*sizeof(char));
    int i = 0;
    int j = 0;
    while (i < string_length) {
        if ((string[i+1] == ',') && !((!isspace(string[i])) && (isspace(string[i+2])))) {
            new_string[j] = ',';
            j++;
            new_string[j] = ' ';
            i+=2;
        }
        else{
            new_string[j] = string[i];
            j++;
            i++;
        }

    }
    return new_string;
}

void capitalize_beginning(char *string, int string_length) {
    /* code */
}
