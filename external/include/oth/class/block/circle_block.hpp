#ifndef CIRCLE_BLOCK
#define CIRCLE_BLOCK

#include <string>
#include <SFML/Graphics.hpp>
#include <oth/render.hpp>
#include "block.hpp"

class CircleBlock: public Block {
    public:
        CircleBlock(const sf::Color& color, float radius);
        void shapeRender(sf::RenderWindow* window) override;

    private:
        std::string id;
        sf::CircleShape shape;
};

#endif