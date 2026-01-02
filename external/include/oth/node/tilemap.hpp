#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <oth/engine/render.hpp>
#include <oth/engine/display.hpp>
#include <SFML/Graphics.hpp>

class Tilemap {
    public:
        Tilemap(int priority);
        void renderTiles(sf::RenderWindow* window);
        void setTile(int yIndex, int xIndex, Render* tile);
        int getPriority();

    private:
        Render* tiles[800 / 40][1080 / 40];
        int priority;
};

#endif