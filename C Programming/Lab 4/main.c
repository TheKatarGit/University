#include "stringlib.h"

int main() {
    char        str1[] = "abcde2fghi3jk4l";
    const char  str2[] = "y";
    const int   len1 = 15;
    const int   len2 = 2;
    char        *myret;
    char        *stdret;

    myret = new_strpbrk(str1, str2, len1, len2);
    stdret = strpbrk(str1, str2);

    if(stdret == myret){
        printf("Strpbrk test passed\n");
    }
    else{
        printf("Strpbrk test failed\n");
    }
    char *str = new_strdup(str1, len1);
    char *stdstr = strdup(str1);
    for (size_t i = 0; i < strlen(stdstr); i++) {
        if (str1[i] != stdstr[i]) {
            printf("Strdup test failed\n");
            break;
        }
    }
    printf("Strdup test passed\n");
    return 0;
}
