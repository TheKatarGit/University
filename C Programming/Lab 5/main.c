#include "ISOlib.h"

int main(int argc, char const *argv[]) {
    //char string[100] = "";
    FILE *f;
    FILE *fo;
    f = fopen("kek.txt","r");
    fo = fopen("keko.txt","w");
    char* string = "";
    char* next_string = "";
    char *blah;
    int end_is_near = 0;
    string = read_str(f);
    while(string){

      puts("Cycle started");
      next_string = read_str(f);
      if (feof(f)) {
        end_is_near = 1;
      }
      puts("Success");
      blah = remove_extra_spaces(string, strlen(string));
      // printf("%s\n",blah );
      if (blah[strlen(blah) - 2] != '.' && end_is_near){
        strcat(blah,".");
      }
      printf("blah after space rem - %s\n",blah );
      blah = replace_commas(blah, strlen(blah));
      printf("blah after com rep - %s\n",blah );
      blah = capitalize_beginning(blah, strlen(blah));
      printf("blah after cap - %s\n",blah );
      fprintf(fo,"%s",blah);
      printf("LOL\n");
      if (!end_is_near) {
        strcpy(string, next_string);
      }
      else{
        break;
      }

    }

    fclose(f);
    fclose(fo);

    free(blah);
    return 0;
}
