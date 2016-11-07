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
    fpos_t pos;
    outFile = fopen("out.txt", "w");
    int len = strlen(replacee);
    // len--;
    char *current = malloc(len*sizeof(char));
    char *res;
    int counter = 0;
    int skip = 0;
    fgetpos(inFile, &pos);
    fgets(current,len+1,inFile);
    do {
        printf("%s\n",current);
        if (counter > len){
            // counter = 0;
            if (!strcmp(current, replacee)){
                printf("BLYAT\n");
                fprintf(outFile, "%s", replacer);
                // rearrange(current, letter, len);
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
                // rearrange(current, letter, len);
                counter -=1;
            }
        }

        // *(current + counter) = letter;

        fsetpos(inFile, &pos);
        // printf("POS %d\n",ftell(inFile));
        fgetc(inFile);
        // printf("POS %d\n",ftell(inFile));
        fgetpos(inFile, &pos);
        fgets(current,len+1,inFile);
        // printf("%s\n",current);

        // printf("POS %d\n",ftell(inFile) );
        // counter++;
        // printf("%c\n",letter);

    } while(!feof(inFile));
    fprintf(outFile, "\n");
    // free(current);
    fclose(outFile);
}
