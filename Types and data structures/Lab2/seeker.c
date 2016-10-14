#include "seeker.h"

void seekStep(Data_t* d){
    int randNum;
    CellString_t Neighbours = getNeighbours(d, d->startPoint, 1);
    if(Neighbours.size){
        setMode(d->startPoint, d->maze, WAY);
        randNum     = randomRange(0, Neighbours.size-1);
        d->cellNext = Neighbours.cells[randNum]; //выбираем случайного соседа
        push(d->startPoint, d->stack); //заносим текущую точку в стек
        d->startPoint = d->cellNext; //делаем соседнюю точку текущей и отмечаем ее посещенной
        free(Neighbours.cells);
        // printBitmap(d->maze,20,20);
    }
    else if(d->stack->size){
        setMode(d->startPoint, d->maze, SEEKED);
        d->startPoint = pop(d->stack);
        free(Neighbours.cells);
    }
    else{
        d->error = true;
        free(Neighbours.cells);
    }
}
