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

char *read_str(FILE *f){
  int buf = 5;
  char tmp[5];
  char* str = malloc(5);
  char* temp;
  temp = str;
  if (!f){return _FILE_ERR_;}
  //printf("\nstart point - %p\n",str);
  //str[4] = '\0';
  int strl = 5;
  int strlt = 0;
  char *fl;
  while(temp){
    temp = fgets(tmp,buf,f);
    if(temp == NULL){return NULL;}
    strcat(str,temp);
    if(temp[strlen(temp)-1] == '\n'){return str;}
    //printf("\ntemp - %s\n",temp);
    //printf("\nstr - %s\n",str);
    //printf("\nstrlen - %d\n",strl);
    if(temp){
      strl+=buf;
      //printf("\nstrl - %d\n",strl);
      //printf("\nstrlen - %lu\n",strlen(str));
      //printf("\ncur point - %p\n",str);
      str = (char*)realloc(str,strl);
      //printf("\nstrlen after - %lu\n",strlen(str));
      //printf("\nsize of chr - %lu\n",sizeof(str));
    }
  }
  puts(temp);
  //str[strl-1] = '\0';
  return str;
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
