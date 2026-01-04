#include <oth/node/tilemap.hpp>
#include <oth/node/block/rectangle_block.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Tilemap::Tilemap(int priority)
{
    this->priority = priority;
}

int Tilemap::getPriority()
{
    return this->priority;
}

void Tilemap::setTile(int yIndex, int xIndex, RectangleBlock *tile)
{
    this->tiles[yIndex][xIndex] = tile;
}

void Tilemap::renderTiles(sf::RenderWindow *window)
{
    int yVal = 0;
    int xVal = 0;

    while (yVal < (640 / 32))
    {
        while (xVal < (864 / 32))
        {
            if (tiles[yVal][xVal])
            {
                tiles[yVal][xVal]->shapeRender(window);
            }
            xVal++;
        }
        xVal = 0;
        yVal++;
    }
}