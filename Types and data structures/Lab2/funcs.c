#include "funcs.h"

void printBitmap(MazeMatrix_t maze, uint16_t w, uint16_t h){
    printf("\n");
    for(uint16_t i = 0; i < h; i++){
        printf("\n");
        for(uint16_t j = 0; j < w; j++){
                if(maze[i][j] == WALL)
                    printf("\u25A0 ");
                else if (maze[i][j] == WAY)
                  printf("\u25AB ");
                else if (maze[i][j] == SEEKED)
                  printf("\u25AA ");
                else if (maze[i][j] == EXIT)
                printf("\u2622 ");
                else
                    printf("\u00A0 ");
        }
    }
    printf("\n");
}
