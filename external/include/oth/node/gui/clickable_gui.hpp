#ifndef CLICKABLE_GUI_HPP
#define CLICKABLE_GUI_HPP

#include <oth/engine/render.hpp>
#include <SFML/Graphics.hpp>

class ClickableGui: public Render {
    public:
        ClickableGui(const sf::Color& color, float width, float height, float posX, float posY);

        void shapeRender(sf::RenderWindow *window) override;
        void click();
    
    private:
        sf::RectangleShape shape;
};

#endif