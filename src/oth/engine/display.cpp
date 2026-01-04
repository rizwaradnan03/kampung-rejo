#include <oth/engine/display.hpp>
#include <SFML/Graphics.hpp>

void Display::setWidth(int w){
    this->width = static_cast<unsigned int>(w);
}

void Display::setHeight(int h){
    this->height = static_cast<unsigned int>(h);
}