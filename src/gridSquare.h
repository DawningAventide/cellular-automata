#pragma once
#include "constants.h"
#include <SFML/Graphics.hpp>

enum squareState {
    DEAD,
    DYING,
    ALIVE,
    GROWING
};





class gridSquare {
public:
    std::array<gridSquare, 4> &getNeighbors();
    int addNeighbor(gridSquare* cell);
public:
    int log_pos[2];
    sf::RectangleShape shape;
    squareState state;
    float capacity;






};