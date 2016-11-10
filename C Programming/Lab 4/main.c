#include "stringlib.h"

int main() {
    char  str1[] = "abcde2fghi3jk4l";
    char  str2[] = "a";
    int   len1 = strlen(str1);
    int   len2 = strlen(str2);
    char        *myret;
    char        *stdret;

    myret = new_strpbrk(str1, str2, len1, len2);
    stdret = strpbrk(str1, str2);

    if(stdret == myret){
        printf("Strpbrk 1 test passed\n");
    }
    else{
        printf("Strpbrk 1 test failed\n");
    }

    char str3[] = "sdfghjk";
    char str4[] = "qwek";
    len1 = strlen(str3);
    len2 = strlen(str4);

    myret = new_strpbrk(str3, str4, len1, len2);
    stdret = strpbrk(str3, str4);

    if(stdret == myret){
        printf("Strpbrk 2 test passed\n");
    }
    else{
        printf("Strpbrk 2 test failed\n");
    }

    char str5[] = "sdfghjk";
    char str6[] = "yygy";
    len1 = strlen(str5);
    len2 = strlen(str6);

    myret = new_strpbrk(str5, str6, len1, len2);
    stdret = strpbrk(str5, str6);

    if(stdret == myret){
        printf("Strpbrk 3 test passed\n");
    }
    else{
        printf("Strpbrk 3 test failed\n");
    }

    char str7[] = "ertyuio";
    char str8[] = "xcvbnm";
    len1 = strlen(str7);
    len2 = strlen(str8);

    myret = new_strpbrk(str7, str8, len1, len2);
    stdret = strpbrk(str7, str8);

    if(stdret == myret){
        printf("Strpbrk 4 test passed\n");
    }
    else{
        printf("Strpbrk 4 test failed\n");
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
