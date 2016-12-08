#include "ISOlib.h"

char *remove_extra_spaces(char *string, int string_length) {
    int i = 0;
    int j = 0;
    char *new_string = malloc(string_length*sizeof(char));
    if (isspace(string[i])) {
      while ((isspace(string[i]))) {
          i++;
      }
    }
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
        if ((string[i]==',')) {
            if (isspace(string[i-1])) {
              j--;
            }
            new_string[j] = ',';
            j++;
            new_string[j] = ' ';
            j++;
            if (isspace(string[i+1])){
              i+=2;
            }
            else{
              i+=1;
            }
        }
        else{
            new_string[j] = string[i];
            j++;
            i++;
        }

    }
    return new_string;
}

char *capitalize_beginning(char *string, int string_length) {
    char *new_string = malloc(string_length*sizeof(char));
    int i = 1;
    int j = 1;
    new_string[0] = toupper(string[0]);
    while (i < string_length) {
        if ((string[i]=='.')) {
            if (isspace(string[i-1])) {
              j--;
            }
            new_string[j++] = '.';
            if (isspace(string[i+1])){
              i+=2;
            }
            else{
              i+=1;
            }
            new_string[j++] = ' ';
            new_string[j++] = toupper(string[i++]);
          }
        else{
            new_string[j] = string[i];
            j++;
            i++;
        }
      }
    return new_string;
}
