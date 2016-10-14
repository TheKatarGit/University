#ifndef TYPES_H
#define TYPES_H
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct cods_s{
    int x;
    int y;
};

typedef struct cods_s Cell_t;

typedef enum CellTypes { CELL, GENCELL, GENVISITED, WALL, WAY, SEEKED, EXIT } CellType_t;

typedef int*  MazeString_t;
typedef int** MazeMatrix_t;

typedef struct CellString_s {
    Cell_t   *cells;
    int  size;
} CellString_t;

typedef struct Node_s {
    Cell_t cell;
    struct Node_s *next;
} Node_t;

typedef struct Stack_s {
    Node_t*  top;
    int size;
} Stack_t;

typedef struct mazeData_s {
    int    width;
    int    height;
    int    unvisitedNum;
    MazeMatrix_t  maze;
    Stack_t    *stack;
    Cell_t      startPoint;
    Cell_t      exitPoint;
    Cell_t      cellNext;
    bool        error;
} Data_t;

#endif // TYPES_H
