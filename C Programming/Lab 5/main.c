#include "ISOlib.h"

int main(int argc, char const *argv[]) {
    char string[100] = "test,string.here.";
    char *blah = remove_extra_spaces(string, strlen(string));
    printf("%s\n",blah );
    blah = replace_commas(blah, strlen(blah));
    printf("%s\n",blah );
    blah = capitalize_beginning(blah, strlen(blah));
    printf("%s\n",blah );
    return 0;
}
