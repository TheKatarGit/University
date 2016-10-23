#include "flowlib.h"

void rearrange(char *array, int letter, int len) {
    if (len == 0){
        *array = letter;
        return;
    }
    for (size_t i = 0; i < len - 1; i++) {
        *(array + i) = *(array + i + 1);
    }
    *(array + len) = letter;
}

void go_through(FILE *inFile, const char *replacee, const char *replacer){
    FILE *outFile;
    outFile = fopen("out.txt", "w");
    int len = strlen(replacee);
    len--;
    char *current = malloc(len*sizeof(char));
    int letter;
    int counter = 0;
    letter = fgetc(inFile);
    do {
        if (counter > len){
            counter = 0;
            if (!strcmp(current, replacee)){
                fprintf(outFile, "%s", replacer);
                rearrange(current, letter, len);
            }
            else{
                fprintf(outFile, "%s", current);
                memset(current, 0, len);
            }
        }
        *(current + counter) = letter;
        letter = fgetc(inFile);
        counter++;

    } while (letter != EOF);
    free(current);
    fclose(outFile);
}
