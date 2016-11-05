#include "flowlib.h"

void rearrange(char *array, int letter, int len) {
    if (len == 0){
        *array = letter;
        return;
    }
    for (size_t i = 0; i <= len - 1; i++) {
        *(array + i) = *(array + i + 1);

    }
    // *(array + len) = letter;
}

void go_through(FILE *inFile, const char *replacee, const char *replacer){
    FILE *outFile;
    outFile = fopen("out.txt", "w");
    int len = strlen(replacee);
    len--;
    char *current = malloc(len*sizeof(char));
    int letter;
    int counter = 0;
    int skip = 0;
    letter = fgetc(inFile);
    do {
        if (counter > len){
            // counter = 0;
            if (!strcmp(current, replacee)){
                printf("BLYAT\n");
                fprintf(outFile, "%s", replacer);
                rearrange(current, letter, len);
                counter-=1;
                skip = 2;
            }
            else
            {
                if (skip == 0)
                {
                    printf("SUKA\n" );
                    fprintf(outFile, "%s", current);
                    // skip = 0;
                }
                else
                {
                    skip--;
                }
                rearrange(current, letter, len);
                counter -=1;
            }
        }

        *(current + counter) = letter;
        printf("%s\n",current );
        letter = fgetc(inFile);
        counter++;
        // printf("%c\n",letter);

    } while (letter != EOF);
    fprintf(outFile, "\n");
    free(current);
    fclose(outFile);
}
