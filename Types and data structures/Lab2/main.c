#include "generator.h"

int main(int argc, char const *argv[]) {
  MazeMatrix_t maze = init(20,20);
  Cell_t startPoint;
  startPoint.x = 5;
  startPoint.y = 5;
  Data_t d = initGeneratorData(20,20,startPoint);
  generateStep(&d);
  printBitmap(maze,20,20);
  return 0;
}
