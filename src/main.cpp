#include <SFML/Graphics.hpp>
#include <oth/engine/game.hpp>
#include <oth/engine/config.hpp>
#include <oth/engine/display.hpp>

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({Display::width, Display::height}), "Kampung Rejo");
    
    Game g;
    g.Run(window);

    return 0;
}