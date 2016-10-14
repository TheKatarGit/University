#ifndef COMMON_H
#define COMMON_H
#include "generator.h"
#include "types.h"

Data_t initGeneratorData(int width, int height, Cell_t startPoint);

Data_t initSeekerData(Data_t d, Cell_t startPoint, Cell_t exitPoint);

//generator and seeker common functions
void         setMode (Cell_t cell, MazeMatrix_t maze, CellType_t type);

CellString_t getNeighbours(Data_t *data, Cell_t cell, int distance);

int     randomRange (int low, int high);

#endif // COMMON_H
