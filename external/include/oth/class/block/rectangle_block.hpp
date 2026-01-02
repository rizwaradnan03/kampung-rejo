#ifndef RECTANGLE_BLOCK
#define RECTANGLE_BLOCK

#include <string>
#include <SFML/Graphics.hpp>
#include <oth/render.hpp>
#include "block.hpp"

class RectangleBlock: public Block {
    public:
        RectangleBlock(const sf::Color& color, float width, float height);
        void shapeRender(sf::RenderWindow* window) override;

    private:
        std::string id;
        sf::RectangleShape shape;
};

#endif