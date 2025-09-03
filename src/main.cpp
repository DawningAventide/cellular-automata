#include <SFML/Graphics.hpp>
#include <iostream>
#include "xoshiro256ss.h"
#include <random>
#include "gridSquare.h"



using u64 = unsigned long long;

typedef gridSquare gridType[GRID_WIDTH][GRID_HEIGHT];

double getU01(xoshiro256ss &g) {
    u64 base = g();
    u64 max = u64 (-1);
    double uniform = double(base) / double(max);

    return uniform;
}



void buildGrid(xoshiro256ss g, gridType &grid, float size, float border, float lineweight) {


    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            float x_base = border + x*size + x*lineweight;
            float y_base = border + y*size + y*lineweight;

            
            sf::RectangleShape shape = sf::RectangleShape({size, size});
            shape.setFillColor(sf::Color::White);
            shape.setPosition({x_base, y_base});

            int log_pos[2] = {x,y};
            gridSquare tmp_struct = gridSquare();
            if(getU01(g) <= .25) {
                tmp_struct.state = DEAD;
                shape.setFillColor(sf::Color::Red);
            } else {
                tmp_struct.state = ALIVE;
                shape.setFillColor(sf::Color::Green);
            }
            tmp_struct.shape = shape;
            tmp_struct.capacity = 50.f;
            grid[x][y] = tmp_struct;
        }
    }
    
    return;
}

void drawGrid(sf::RenderWindow &window, gridType &grid) {
    
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            sf::RectangleShape shape = grid[x][y].shape;
            window.draw(shape);
           
        }
    }
    
    return;
}

void updateGrid(gridType &grid, xoshiro256ss g) {

}


int main()
{


    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Gridworld");
    window.setFramerateLimit(144);
    srand(time(0));
    xoshiro256ss g(rand());
    
    


    std::cout << "Initializing Grid.\n";
    gridType grid;

    std::cout << "Building Grid.\n";
    buildGrid(g, grid, SQUARE_SIZE, BORDER_SIZE, LINE_WEIGHT);
    std::cout << "Grid Build Successful.\n";

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

        window.clear(sf::Color::Black);
        
        drawGrid(window, grid);

        window.display();

    }
   
}
