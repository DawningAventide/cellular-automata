#pragma once
#include "constants.h"
#include <iostream>
#include "gridSquare.h"

class Environment {
public:
    float tile_size;
    float border_size;
    float line_width;

private:
    gridSquare grid[GRID_WIDTH][GRID_HEIGHT];


public:
    gridSquare* getCell(unsigned int x, unsigned int y);

    void addCell(unsigned int x, unsigned int y, gridSquare cell) ;

};