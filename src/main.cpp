#include <SFML/Graphics.hpp>
#include <oth/engine/display.hpp>
#include <oth/engine/input.hpp>
#include <oth/engine/config.hpp>
#include <oth/engine/player.hpp>
#include <oth/node/screen.hpp>
#include <oth/node/block/rectangle_block.hpp>
#include <oth/node/tilemap.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({Display::width, Display::height}), "Kampung Rejo");
    Player py(sf::Color::Green, 150, 100);
    Screen scr;
    Config cf;
    RectangleBlock bl(sf::Color::Red, 40, 40);

    Tilemap tm(1);

    int yVal = 0, xVal = 0;
    while (yVal < 20)
    {
        while (xVal < 27){
            tm.setTile(yVal, xVal, &bl);
            xVal++;
        }

        xVal = 0;
        yVal++;
    }

    while (window->isOpen())
    {
        cf.setTime(0.02);

        // window->clear(sf::Color::Blue);

        tm.renderTiles(window);

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            else
            {
                // py.Handle(*event);
            }
        }

        // py.shapeRender(window);
        window->display();
    }
    return 0;
}