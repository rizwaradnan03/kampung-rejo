#include <oth/node/gui/clickable_gui.hpp>

ClickableGui::ClickableGui(const sf::Color& color, float width, float height, float posX, float posY){
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(color);

    this->shape.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
    this->shape.setPosition(sf::Vector2f(posX, posY));
}

void ClickableGui::_shape_render(sf::RenderWindow *window){
    window->draw(this->shape);
}

void ClickableGui::click(){}