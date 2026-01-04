#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <oth/node/block/rectangle_block.hpp>
#include <oth/engine/display.hpp>
#include <SFML/Graphics.hpp>

class Tilemap {
    public:
        Tilemap(int priority);
        void renderTiles(sf::RenderWindow* window);
        void setTile(int yIndex, int xIndex, RectangleBlock* tile);
        int getPriority();

    private:
        RectangleBlock* tiles[640 + 32 / 32][864 / 32];
        int priority;
};

#endif