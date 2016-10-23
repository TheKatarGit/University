#include "stringlib.h"

char *new_strpbrk(char *str1, const char *str2, const int len1, const int len2){
    for (size_t i = 0; i < len2; i++) {
        for (size_t j = 0; j < len1; j++) {
            if (*(str1 + j) == *(str2 + i)){
                char *ptr = str1 + j;
                return ptr;
            }
        }
    }
    return NULL;
}

char *new_strdup(const char *str, const int len){
    char *str2 = malloc(len*sizeof(char));
    if (!str2) return NULL;
    for (size_t i = 0; i < len; i++) {
        *(str2 + i) = *(str + i);
    }
    return str2;
}
