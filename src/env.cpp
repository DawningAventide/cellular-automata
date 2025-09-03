#pragma once
#include "env.h"

class Environment {
    
    gridSquare grid[GRID_WIDTH][GRID_HEIGHT];
    
    float tile_size;
    float border_size;
    float line_width;
    Environment *selfptr;


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

    void linkCells() {
        for(int x = 0; x < GRID_WIDTH; x++) {
            for(int y = 0; y < GRID_HEIGHT; y++) {
                gridSquare* current_cell = getCell(x,y);

                if(y > 0) {
                    gridSquare* north_neighbor = getCell(x, y-1);
                    current_cell->addNeighbor(north_neighbor);

                }
                if(y < (GRID_HEIGHT - 1)) {
                    gridSquare* south_neighbor = getCell(x, y+1);
                    current_cell->addNeighbor(south_neighbor);
                }
                if(x > 0) {
                    gridSquare* west_neighbor = getCell(x-1, y);
                    current_cell->addNeighbor(west_neighbor);
                }
                if(x < (GRID_WIDTH - 1)) {
                    gridSquare* east_neighbor = getCell(x+1, y);
                    current_cell->addNeighbor(east_neighbor);
                }
                
            }
        }
    }

};