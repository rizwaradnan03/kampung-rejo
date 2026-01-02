#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <oth/render.hpp>
#include <oth/logic/physics.hpp>

class Block : public Render, public Physics {
    public:
        // Block(const sf::Color& color, float width, float height);
        virtual void shapeRender(sf::RenderWindow* window) override;
};

#endif