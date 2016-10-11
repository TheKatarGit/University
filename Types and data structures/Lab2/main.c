#include "generator.h"
#include "seeker.h"
#include "stdio.h"
int main(int argc, char const *argv[]) {
  int width, height;
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
  // free(seeker.stack);
  // free(seeker.maze);
  free(d.maze);
  return 0;
}
