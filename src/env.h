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
    gridSquare* getCell(unsigned int x, unsigned int y) {
        if(x < GRID_WIDTH && y < GRID_HEIGHT) {
            return &grid[x][y];
        } else {
            std::cout << "Error: Get Index out of bounds.";
            throw(x, y);
        }
    };

    void addCell(unsigned int x, unsigned int y, gridSquare cell) {
        if(x < GRID_WIDTH && y < GRID_HEIGHT) {
            grid[x][y] = cell;
        } else {
            std::cout << "Error: Add Index out of bounds.";
        }
    };

};