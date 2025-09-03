#pragma once
#include "gridSquare.h"


class gridSquare {

    int log_pos[2];
    sf::RectangleShape shape;
    squareState state;
    float capacity;



    std::vector<gridSquare*> neighbors;

    int addNeighbor(gridSquare* cell) {
        neighbors.push_back(cell);
        return 0;
    }


};
