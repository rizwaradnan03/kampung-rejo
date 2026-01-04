#include <oth/node/block/circle_block.hpp>
#include <SFML/Graphics.hpp>
#include <oth/logic/generator.hpp>

CircleBlock::CircleBlock(const sf::Color& color, float radius){
    this->id = Generator::generateId("circle_block");

    this->shape.setRadius(radius);
    this->shape.setFillColor(color);

    this->shape.setOrigin({radius, radius});
}

void CircleBlock::_shape_render(sf::RenderWindow* window){
    window->draw(this->shape);
}