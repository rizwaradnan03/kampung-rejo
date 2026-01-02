#include <oth/node/block/rectangle_block.hpp>
#include <SFML/Graphics.hpp>
#include <oth/logic/generator.hpp>

RectangleBlock::RectangleBlock(const sf::Color& color, float width, float height){
    this->id = Generator::generateId("rectangle_block");

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(color);

    this->shape.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
}

void RectangleBlock::shapeRender(sf::RenderWindow* window){
    window->draw(this->shape);
}