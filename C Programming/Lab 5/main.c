#include "ISOlib.h"

int main(int argc, char const *argv[]) {
    //char string[100] = "";
    FILE *f;
    f = fopen("kek.txt","r");
    char* string = read_str(f);
    char *blah = remove_extra_spaces(string, strlen(string));
    printf("%s\n",blah );
    blah = replace_commas(blah, strlen(blah));
    printf("%s\n",blah );
    blah = capitalize_beginning(blah, strlen(blah));
    printf("%s\n",blah );
    free(blah);
    return 0;
}
