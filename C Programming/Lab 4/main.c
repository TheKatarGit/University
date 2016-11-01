#include "stringlib.h"

int main() {
    char        str1[] = "abcde2fghi3jk4l";
    const char  str2[] = "34";
    const int   len1 = 15;
    const int   len2 = 2;
    char        *ret;

    ret = new_strpbrk(str1, str2, len1, len2);

    if(ret){
        printf("First matching character: %c\n", *ret);
    }
    else{
        printf("Character not found");
    }
    char *str = new_strdup(str1, len1);
    printf("%s\n",str);
    return 0;
}