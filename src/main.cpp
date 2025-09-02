#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>

const unsigned int GRID_WIDTH = 20u;
const unsigned int GRID_HEIGHT = 20u;

const unsigned int SCREEN_WIDTH = 1920u;
const unsigned int SCREEN_HEIGHT = 1080u;

typedef sf::RectangleShape gridType[GRID_WIDTH][GRID_HEIGHT];

void buildGrid(sf::RenderWindow &window, gridType &grid, float size, float border, float lineweight) {


    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            float x_base = border + x*size + x*lineweight;
            float y_base = border + y*size + y*lineweight;

            
            sf::RectangleShape shape = sf::RectangleShape({size, size});
            shape.setFillColor(sf::Color::White);
            shape.setPosition({x_base, y_base});
            grid[x][y] = shape;

        }
    }
    
    return;
}

void drawGrid(sf::RenderWindow &window, gridType &grid) {
    
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            sf::RectangleShape shape = grid[x][y];
            window.draw(shape);
           
        }
    }
    
    return;
}


int main()
{


    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Gridworld");
    window.setFramerateLimit(144);

    std::cout << "Initializing Grid.\n";
    gridType grid;

    std::cout << "Building Grid.\n";
    buildGrid(window, grid, 50, 10, 2);
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
