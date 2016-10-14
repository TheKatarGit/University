#include "common.h"

//initialisation finctions
Data_t initGeneratorData(int width, int height, Cell_t startPoint){
    Data_t d;
    d.width        = width;
    d.height       = height;
    d.startPoint.x = startPoint.x;
    d.startPoint.y = startPoint.y;
    d.maze         = init(width, height);
    d.stack        = calloc(1, sizeof(Stack_t));
    d.stack->top   = NULL;
    d.stack->size  = 0;
    d.unvisitedNum = unvisitedCount(width, height, d.maze) - 1;
    d.error        = false;
    setMode(d.startPoint, d.maze, GENVISITED);
    return d;
}

Data_t initSeekerData(Data_t d, Cell_t startPoint, Cell_t exitPoint){
    wipe(d.stack);
    free(d.stack);
    d.maze         = finalize(d.width, d.height, d.maze);
    d.startPoint   = startPoint;
    d.exitPoint    = exitPoint;
    d.stack        = calloc(1, sizeof(Stack_t));
    d.stack->top   = NULL;
    d.stack->size  = 0;
    d.error        = false;
    return d;
}

//generator and seeker common functions
CellString_t getNeighbours(Data_t *data, Cell_t c, int distance){
    int x   = c.x;
    int y   = c.y;
    Cell_t up    = {x, y - distance};
    Cell_t rt    = {x + distance, y};
    Cell_t dw    = {x, y + distance};
    Cell_t lt    = {x - distance, y};
    Cell_t d[4]  = {dw, rt, up, lt};
    int size = 0;

    CellString_t cells;
    cells.cells = malloc(4 * sizeof(Cell_t));

    int     height = data->height;
    int     width  = data->width;
    MazeMatrix_t maze   = data->maze;

    for(int i = 0; i < 4; i++){ //для каждого направдения d
        if(d[i].x > 0 && d[i].x < width && d[i].y > 0 && d[i].y < height){ //если не выходит за границ
            CellType_t mazeCellCurrent = maze[d[i].y][d[i].x];
            Cell_t     cellCurrent     = d[i];
            if(mazeCellCurrent != WALL && mazeCellCurrent != GENVISITED && mazeCellCurrent != SEEKED && mazeCellCurrent != WAY){ //и не посещена\является стеной
                cells.cells[size] = cellCurrent; //записать в массив;
                size++;
            }
        }
    }
    cells.size = size;
    if (cells.cells == NULL){
      free(cells.cells);
    }
    return cells;
}


int randomRange(int low, int high){
    return rand() % (high - low + 1) + low;
}


void setMode(Cell_t c, MazeMatrix_t maze, CellType_t mode){
    int x = c.x;
    int y = c.y;
    maze[y][x] = mode;
}
