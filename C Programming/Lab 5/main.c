#include "ISOlib.h"

int main(int argc, char const *argv[]) {
    //char string[100] = "";
    FILE *f;
    FILE *fo;
    f = fopen("kek.txt","r");
    fo = fopen("keko.txt","w");
    char* string;
    char *blah;
    while(string){
      puts("Cycle started");
      string = read_str(f);
      puts("Sucsess");
      if (string == NULL){return 0;}
      blah = remove_extra_spaces(string, strlen(string));
      printf("blah after space rem - %s\n",blah );
      blah = replace_commas(blah, strlen(blah));
      printf("blah after com rep - %s\n",blah );
      blah = capitalize_beginning(blah, strlen(blah));
      printf("blah after cap - %s\n",blah );
      fprintf(fo,"%s",blah);
      //free(blah);
    }
    fclose(f);
    fclose(fo);

    free(blah);
    return 0;
}
