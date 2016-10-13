#ifndef COMMON_H
#define COMMON_H
#include "generator.h"
#include "types.h"

Data_t initGeneratorData(uint16_t width, uint16_t height, Cell_t startPoint);

Data_t initSeekerData(Data_t d, Cell_t startPoint, Cell_t exitPoint);

//generator and seeker common functions
void         setMode (Cell_t cell, MazeMatrix_t maze, CellType_t type);

CellString_t getNeighbours(Data_t *data, Cell_t cell, int8_t distance);

uint32_t     randomRange (uint32_t low, uint32_t high);

#endif // COMMON_H
