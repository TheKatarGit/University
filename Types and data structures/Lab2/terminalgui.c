#include "terminalgui.h"

void start_labyrinth() {
    clock_t start, end;
    int width, height;
    printf("Input width and height of maze: ");
    start = clock();
    scanf("%d %d",&width, &height);
    Cell_t startPoint;
    startPoint.x = 1;
    startPoint.y = 1;
    Data_t d = initGeneratorData(width,height,startPoint);
    Cell_t exitPoint;
    exitPoint.x = width - 2;
    exitPoint.y = height - 2;
    if (width % 2 == 0) exitPoint.x-=1;
    if (height % 2 == 0) exitPoint.y-=1;
    while (unvisitedCount(width,height,d.maze) > 0) {
      generateStep(&d);
    }
    Data_t seeker = initSeekerData(d,startPoint,exitPoint);
    while ((seeker.startPoint.x != seeker.exitPoint.x || seeker.startPoint.y != seeker.exitPoint.y) && seeker.error != 1) {
      seekStep(&seeker);
    }

    setMode(seeker.exitPoint,seeker.maze, EXIT);
    printBitmap(seeker.maze,width,height);
    wipe(seeker.stack);
    free(seeker.stack);

    for (size_t i = 0; i < height; i++) {
      free(d.maze[i]);
    }
    free(d.maze);
    end = clock();
    printf("Time needed for maze generation and salvation is %lf\n",(double)(end - start));
}

#include <stdio.h>
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
