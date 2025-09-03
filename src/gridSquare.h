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
    // gridSquare(sf::RectangleShape shape, squareState state, float capacity, int log_pos[2]);
    // gridSquare(int log_pos[2]);
    // gridSquare();
public:
    int log_pos[2];
    sf::RectangleShape shape;
    squareState state;
    float capacity;

};