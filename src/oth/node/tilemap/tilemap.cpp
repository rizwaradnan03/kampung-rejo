#include <oth/node/tilemap.hpp>
#include <oth/engine/render.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Tilemap::Tilemap(int priority){
    this->priority = priority;
}

int Tilemap::getPriority(){
    return this->priority;
}

void Tilemap::setTile(int yIndex, int xIndex, Render* tile){
    this->tiles[yIndex][xIndex] = tile;
}

void Tilemap::renderTiles(sf::RenderWindow *window){
    int yVal = 0;
    int xVal = 0;

    while(yVal < (800 / 40)){
        while(xVal < (1080 / 40)){
            this->tiles[yVal][xVal]->shapeRender(window);
            xVal++;
        }

        xVal = 0;
        yVal++;
    }

    std::cout << "YVal : " << yVal << std::endl;
}