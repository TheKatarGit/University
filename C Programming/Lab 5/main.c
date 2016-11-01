#include "ISOlib.h"

int main(int argc, char const *argv[]) {
    char string[36] = "   why     no ,u suck        my.dick";
    printf("%s\n", remove_extra_spaces(string, 36));
    // char *blah2 = replace_commas(blah, 36);
    // char *blah3 = capitalize_beginning(blah2, 36);
    // char *blah4 = remove_extra_spaces(blah3, 36);
    // capitalize_beginning(string, 36);
    // printf("%s\n",string);
    return 0;
}
