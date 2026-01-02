#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <oth/engine/render.hpp>
#include <oth/engine/display.hpp>
#include <SFML/Graphics.hpp>

class Tilemap: public Render {
    public:
        Tilemap(int priority);
        void shapeRender(sf::RenderWindow* window) override;

        int getPriority();

    private:
        Render* tiles[780 / 40][1080 / 40];
        int priority;
};

#endif