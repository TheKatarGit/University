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

int go_through(FILE *inFile, const char *replacee, const char *replacer){
    FILE *outFile;
    fpos_t pos;
    outFile = fopen("out.txt", "w");
    if (outFile == NULL) {
        return -1;
    }
    int len = strlen(replacee);
    char *current = malloc(len*sizeof(char));
    char *res;
    int counter = len;
    int skip = 0;
    fgetpos(inFile, &pos);
    fgets(current,len+1,inFile);
    do {
        if (counter == len){
            if (!strcmp(current, replacee)){
                counter = 0;
                fprintf(outFile, "%s", replacer);
            }
            else
            {
                fprintf(outFile, "%c", current[0]);
                counter--;
            }
        }
        fsetpos(inFile, &pos);
        fgetc(inFile);
        fgetpos(inFile, &pos);
        fgets(current,len+1,inFile);
        counter++;

    } while(!feof(inFile));
    free(current);
    fprintf(outFile, "\n");
    fclose(outFile);
    return 0;
}
