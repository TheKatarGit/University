#ifndef GENERATOR_H
#define GENERATOR_H
#include "types.h"
#include "common.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "math.h"
#include "funcs.h"
#include "stack.h"


bool generate             (Data_t* d);

bool generateStep         (Data_t* d);

MazeMatrix_t init         (int width, int height);

MazeMatrix_t finalize     (int width, int height, MazeMatrix_t maze);

int unvisitedCount(int width, int height, MazeMatrix_t maze);

#endif // GENERATOR_H
