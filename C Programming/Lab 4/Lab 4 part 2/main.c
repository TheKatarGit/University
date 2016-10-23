#include "flowlib.h"

int main(int argc, char const *argv[]) {
    FILE *inFile;
    if (argc < 3){
        printf("Insufficient arguments\n");
        return 0;
    }
    inFile = fopen(argv[1], "r");
    if (!inFile) {printf("Can't open file\n"); return 0;};
    go_through(inFile, argv[2], argv[3]);
    fclose(inFile);
    return 0;
}
